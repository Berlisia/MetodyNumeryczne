#include "Calculator.h"
#include "Lnfromvalues.h"
#include "DataBase.h"
#include "Linearyzator.h"
#include <cmath>

Calculator::Calculator(const DataBase& p_dataBase) :
    m_dataBase(p_dataBase),
    m_accuracy(p_dataBase.getVectorOfSevered(), p_dataBase.getVectorOfOrdinates())
{
    m_lnFromSevered = std::make_unique<LnFromValues>();
    m_linearyzator = std::make_unique<Linearyzator>(p_dataBase.getVectorOfOrdinates(),
                                                    *m_lnFromSevered.get());
}

std::pair<double, double> Calculator::calculate()
{
    m_lnFromSevered->calculateLn(m_dataBase.getVectorOfSevered());
    m_factors = m_linearyzator->calculateFactors();
    calculateResults(m_factors);
    m_accuracy.calculateAccuracyOfLinearRegresion(m_factors);
    return m_factors;
}

const QVector<double> Calculator::getVectorOfResultY()
{
    return m_vectorOfResultY;
}

const QVector<double> Calculator::getVectorOfResultX()
{
    return m_vectorOfResultX;
}

std::map<Factor, double> Calculator::getResultOfFactors()
{
    return m_accuracy.getFactorMap();
}

double Calculator::calculateValueFromX()
{
    return m_factors.first * std::exp(m_factors.second);
}

void Calculator::reset()
{
    m_lnFromSevered.reset(std::make_unique<LnFromValues>().get());
    m_linearyzator.reset(std::make_unique<Linearyzator>(m_dataBase.getVectorOfOrdinates(),
                                                         *m_lnFromSevered.get()).get());
    m_vectorOfResultY.clear();
    m_vectorOfResultX.clear();
    m_factors.first = 0;
    m_factors.second = 0;
    m_accuracy.reset();
}

void Calculator::calculateResults(std::pair<double, double> p_factors)
{
    unsigned size = m_dataBase.getVectorOfOrdinates().size();
    double i = m_dataBase.getVectorOfOrdinates()[0];
    for(; i < m_dataBase.getVectorOfOrdinates()[size - 1]; i = i + 0.002)
    {
        m_vectorOfResultX.append(i);
        m_vectorOfResultY.append(p_factors.first * std::exp(p_factors.second * i));
    }

}

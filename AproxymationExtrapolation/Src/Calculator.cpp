#include "Calculator.h"
#include "Lnfromvalues.h"
#include "DataBase.h"
#include "Linearyzator.h"

Calculator::Calculator(const DataBase& p_dataBase) : m_dataBase(p_dataBase)
{
    m_lnFromSevered = std::make_unique<LnFromValues>(p_dataBase.getVectorOfSevered());
    m_linearyzator = std::make_unique<Linearyzator>(p_dataBase.getVectorOfOrdinates(),
                                                    *m_lnFromSevered.get());
}

std::pair<float, float> Calculator::calculate()
{
    m_lnFromSevered->calculateLn(m_dataBase.getVectorOfSevered());
    std::pair<float, float> factors = m_linearyzator->calculateFactors();
    calculateResults(factors);
    return factors;
}

const QVector<double> Calculator::getVectorOfResultY()
{
    return m_vectorOfResultY;
}

const QVector<double> Calculator::getVectorOfResultX()
{
    return m_vectorOfResultX;
}

void Calculator::calculateResults(std::pair<float, float> p_factors)
{
    unsigned size = m_dataBase.getVectorOfOrdinates().size();
    float i = m_dataBase.getVectorOfOrdinates()[0];
    for(; i < m_dataBase.getVectorOfOrdinates()[size - 1]; i = i + 0.002)
    {
        m_vectorOfResultX.append(i);
        m_vectorOfResultY.append(p_factors.first * exp(p_factors.second * i));
    }

}

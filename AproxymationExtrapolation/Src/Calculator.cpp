#include "Calculator.h"
#include "Lnfromvalues.h"
#include "DataBase.h"
#include "Linearyzator.h"
#include <cmath>

Calculator::Calculator(const DataBase& p_dataBase) :
    m_dataBase(p_dataBase),
    m_accuracy(p_dataBase.getVectorOfSevered(), p_dataBase.getVectorOfOrdinates())
{
    /*m_lnFromSevered = std::make_unique<LnFromValues>();
    m_linearyzator = std::make_unique<Linearyzator>(m_dataBase.getVectorOfOrdinates(),
                                                    *m_lnFromSevered.get());*/
}

FunctionFactors Calculator::calculate()
{
    findCompartments();

    for(int i = 0; i < m_compartments.size(); i++)//indeksy X
    {
        QVector<double> compartmentY;//dany przedział
        QVector<double> compartmentX;
        for(int j = m_compartments[i]; m_dataBase.getVectorOfSevered()[j] <=
                                          m_dataBase.getVectorOfSevered().end(); j++)//lepsze przerwanie pętli
        {
            compartmentY.append(m_dataBase.getVectorOfSevered()[j]);
            compartmentX.append(m_dataBase.getVectorOfOrdinates()[j]);
        }
        const QVector<double> lncompartmentY = ln(compartmentY);
        Linearyzator m_linearyzator(compartmentX, lncompartmentY);
        std::pair<double, double> l_factors = m_linearyzator.calculateFactors();
        m_factors.append(l_factors);
        calculateResults(l_factors);
        //m_accuracy.calculateAccuracyOfLinearRegresion(l_factors); //TODO moze średnia?
    }
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

double Calculator::calculateValueFromX(double p_valueX)
{
    return 0;//m_factors.first * std::exp(p_valueX * m_factors.second);
}

void Calculator::reset()
{
//    m_lnFromSevered.reset(new LnFromValues());
//    m_linearyzator.reset(new Linearyzator(m_dataBase.getVectorOfOrdinates(),
//                                          *m_lnFromSevered.get()));
    m_vectorOfResultY.clear();
    m_vectorOfResultX.clear();
    m_factors.clear();
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

void Calculator::findCompartments()
{
    bool increase = true;
    if(m_dataBase.getVectorOfSevered()[0] > m_dataBase.getVectorOfSevered()[1])//sprawdzenie czy zaczynamy funkcja rosnącą
        increase = false;

    double oldValue = m_dataBase.getVectorOfSevered().first();
    for(int i = 0; i <  m_dataBase.getVectorOfSevered().size(); i++)
    {
        double value = m_dataBase.getVectorOfSevered()[i];
        if(value > oldValue && increase == false)// czy nadal maleje
        {
            increase = true;
            m_compartments.push_back(i - 1); //nowy przedział gdy zaczyna rosnąć
        }
        else if(value < oldValue && increase == true)// czy nadal rośnie
        {
            increase = false;
            m_compartments.push_back(i - 1); //nowy przedział gdy zaczyna maleć
        }
        oldValue = value;
    }

    m_compartments.push_back(m_dataBase.getVectorOfSevered().size());
}

const QVector<double> Calculator::prepareCompartments()
{
    QVector<double> l;
    return l;
}

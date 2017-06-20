#include "Calculator.h"
#include "Lnfromvalues.h"
#include "DataBase.h"
#include "Linearyzator.h"
#include <cmath>

Calculator::Calculator(const DataBase& p_dataBase) :
    m_dataBase(p_dataBase)
{
}

FunctionFactors Calculator::calculate()
{
    findCompartments();
    for(auto compartment : m_compartments)
    {
        QVector<double> compartmentY;//dany przedział
        QVector<double> compartmentX;
        for(int i = compartment.first; i < m_dataBase.getVectorOfOrdinates()[compartment.second]; i++)
        {
            compartmentY.append(m_dataBase.getVectorOfSevered()[i]);
            compartmentX.append(m_dataBase.getVectorOfOrdinates()[i]);
        }
        const QVector<double> lncompartmentY = ln(compartmentY);
        Linearyzator m_linearyzator(compartmentX, lncompartmentY);
        std::pair<double, double> l_factors = m_linearyzator.calculateFactors();
        m_factors.append(l_factors);
        calculateResults(l_factors, compartment.first, compartment.second);
        Accuracy m_accuracy(compartmentY, compartmentX);
        m_accuracy.calculateAccuracyOfLinearRegresion(l_factors);
        m_accuracyFactors.append(m_accuracy.getFactorMap());
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

AccuracyFactors Calculator::getResultOfFactors()
{
    return m_accuracyFactors;
}

const Compartments Calculator::getCompartments()
{
    return m_compartments;
}

void Calculator::reset()
{
    m_vectorOfResultY.clear();
    m_vectorOfResultX.clear();
    m_factors.clear();
    m_compartments.clear();
    m_factors.clear();
    m_accuracyFactors.clear();
}

void Calculator::calculateResults(std::pair<double, double> p_factors, int begin, int end)
{
    double i = m_dataBase.getVectorOfOrdinates()[begin];
    for(; i < m_dataBase.getVectorOfOrdinates()[end]; i = i + 0.002)
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
    int oldIndex = 0;
    for(int i = 0; i <  m_dataBase.getVectorOfSevered().size(); i++)
    {
        double value = m_dataBase.getVectorOfSevered()[i];
        if(value > oldValue && increase == false)// czy nadal maleje
        {
            increase = true;
            m_compartments.append(std::pair<int,int>(oldIndex, i - 1)); //nowy przedział gdy zaczyna rosnąć
            oldIndex = i - 1;
        }
        else if(value < oldValue && increase == true)// czy nadal rośnie
        {
            increase = false;
            m_compartments.append(std::pair<int,int>(oldIndex, i - 1)); //nowy przedział gdy zaczyna maleć
            oldIndex = i - 1;
        }
        oldValue = value;
    }

    m_compartments.append(std::pair<int,int>(oldIndex, m_dataBase.getVectorOfSevered().size()-1));
}


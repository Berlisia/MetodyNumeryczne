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
    std::pair<float, float> factors = m_linearyzator->calculateFactors();
    calculateResults(factors);
    return factors;
}

QVector<float> &Calculator::getVectorOfResultY()
{
    return m_vectorOfResultY;
}

QVector<float> &Calculator::getVectorOfResultX()
{
    return m_vectorOfResultX;
}

void Calculator::calculateResults(std::pair<float, float> p_factors)
{
    for(unsigned i = 0; i < m_dataBase.getVectorOfOrdinates().size(); i++)
    {
        float x = m_dataBase.getVectorOfOrdinates()[i];
        float y = p_factors.first * exp(p_factors.second * x);
        m_vectorOfResultX.append(x);
        m_vectorOfResultY.append(y);
    }

}

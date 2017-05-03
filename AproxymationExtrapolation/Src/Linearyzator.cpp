#include "Linearyzator.h"
#include "Lnfromvalues.h"
#include <cmath>
using namespace std;

pair<float, float> Linearyzator::calculateFactors()
{
    float factorA1 = calculateA1();
    float factorA0 = exp(calculateA0(factorA1)); //1.000144349116847
    pair<float, float> factors(factorA0, factorA1);
    return factors;
}

float Linearyzator::calculateA1()
{
    int n = m_vectorOfOrdinates.size();
    float A1 = ((n * sumOfMultiplicationXY()) - (sumOfX()*sumOfY())) /
               ((n * sumOfX2() - (sumOfX()*sumOfX())));
    return A1;
}

float Linearyzator::calculateA0(const float factorA1)
{
    float averageZ = average(m_vectorOfLnSevered.getVectorOfSevered().begin(),
                             m_vectorOfLnSevered.getVectorOfSevered().end());
    float averageX = average(m_vectorOfOrdinates.begin(), m_vectorOfOrdinates.end());

    return averageZ - (factorA1 * averageX);
}

float Linearyzator::sumOfMultiplicationXY()
{
    vector<float> l_vectorMultiplication;
    for(unsigned i = 0; i < m_vectorOfLnSevered.getVectorOfSevered().size(); i++)
    {
        l_vectorMultiplication.push_back(m_vectorOfOrdinates[i] *
                                         m_vectorOfLnSevered.getVectorOfSevered()[i]);
    }
    return accumulate(l_vectorMultiplication.begin(), l_vectorMultiplication.end(), 0);
}

float Linearyzator::sumOfX()
{
    return accumulate(m_vectorOfOrdinates.begin(), m_vectorOfOrdinates.end(), 0);
}

float Linearyzator::sumOfY()
{
    return accumulate(m_vectorOfLnSevered.getVectorOfSevered().begin(),
                      m_vectorOfLnSevered.getVectorOfSevered().end(),
                      0);
}

float Linearyzator::sumOfX2()
{
    vector<float> l_vectorMultiplication;
    for(unsigned i = 0; i < m_vectorOfLnSevered.getVectorOfSevered().size(); i++)
    {
        l_vectorMultiplication.push_back(m_vectorOfOrdinates[i] *
                                         m_vectorOfOrdinates[i]);
    }
    return accumulate(l_vectorMultiplication.begin(), l_vectorMultiplication.end(), 0);
}



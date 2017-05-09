#include "Linearyzator.h"
#include "Lnfromvalues.h"
#include <cmath>
using namespace std;

pair<double, double> Linearyzator::calculateFactors()
{
    double factorA1 = calculateA1();
    double factorA0 = exp(calculateA0(factorA1));
    pair<double, double> factors(factorA0, factorA1);
    return factors;
}

double Linearyzator::calculateA1()
{
    int n = m_vectorOfOrdinates.size();
    double sumX = sum(m_vectorOfOrdinates.begin(), m_vectorOfOrdinates.end());
    double sumY = sum(m_vectorOfLnSevered.getVectorOfSevered().begin(),
                      m_vectorOfLnSevered.getVectorOfSevered().end());

    double A1 = ((n * sumOfMultiplicationXY()) - (sumX * sumY)) /
                ((n * sumOfX2() - (sumX * sumX)));
    return A1;
}

double Linearyzator::calculateA0(const double factorA1)
{
    double averageZ = mean(m_vectorOfLnSevered.getVectorOfSevered().begin(),
                           m_vectorOfLnSevered.getVectorOfSevered().end());
    double averageX = mean(m_vectorOfOrdinates.begin(),
                           m_vectorOfOrdinates.end());
    return averageZ - (factorA1 * averageX);
}

double Linearyzator::sumOfMultiplicationXY()
{
    vector<double> l_vectorMultiplication;
    for(signed i = 0; i < m_vectorOfLnSevered.getVectorOfSevered().size(); i++)
    {
        l_vectorMultiplication.push_back(m_vectorOfOrdinates[i] *
                                         m_vectorOfLnSevered.getVectorOfSevered()[i]);
    }
    return sum(l_vectorMultiplication.begin(), l_vectorMultiplication.end());
}


double Linearyzator::sumOfX2()
{
    vector<double> l_vectorMultiplication;
    for(signed i = 0; i < m_vectorOfLnSevered.getVectorOfSevered().size(); i++)
    {
        l_vectorMultiplication.push_back(m_vectorOfOrdinates[i] *
                                         m_vectorOfOrdinates[i]);
    }
    return sum(l_vectorMultiplication.begin(), l_vectorMultiplication.end());
}



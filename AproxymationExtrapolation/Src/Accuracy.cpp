#include "Accuracy.h"
#include "Lnfromvalues.h"
#include "Linearyzator.h"
#include <cmath>

Accuracy::Accuracy(const QVector<double>& p_vectorOfResultY, const QVector<double>& p_vectorOfResultX) :
    m_vectorOfResultY(p_vectorOfResultY),
    m_vectorOfResultX(p_vectorOfResultX)
{
    m_lnFromSevered = std::make_unique<LnFromValues>();
}

void Accuracy::calculateAccuracyOfLinearRegresion(const std::pair<double, double> p_factors)
{
    m_lnFromSevered->calculateLn(m_vectorOfResultY);
    signed l_numberOfElements = m_lnFromSevered->getVectorOfSevered().size();
    double St = sumOfsquaresOfDeviations();
    double Sy = standardDeviation(St, l_numberOfElements);
    double Sr = standardErrorOfEstymation(p_factors, l_numberOfElements);
    double Syx = standardDeviationForRegresionLine(Sr, l_numberOfElements);
    double r2 = (St - Sr)/St;
    m_factorMap[Factor::coefficientOfdetermination] = r2;
    double r = std::sqrt(r2);
    m_factorMap[Factor::correlationCoefficient] = r;
}

std::map<Factor, double> Accuracy::getFactorMap()
{
    return m_factorMap;
}

double Accuracy::standardDeviation(double p_sumOfsquaresOfDeviations, double p_sizeOfArray)
{
    double Sy = std::sqrt(p_sumOfsquaresOfDeviations/(p_sizeOfArray - 1));
    m_factorMap[Factor::standardDeviation] = Sy;
    return Sy;
}

double Accuracy::sumOfsquaresOfDeviations()
{
    const double meanOfLnSevered = mean(m_lnFromSevered->getVectorOfSevered().begin(), //y średnia
                                        m_lnFromSevered->getVectorOfSevered().end());

    QVector<double> differenceInSquareVector; // (y - yśr)^2
    for(auto valueY : m_lnFromSevered->getVectorOfSevered())
    {
        differenceInSquareVector.append((std::pow(valueY - meanOfLnSevered, 2.0)));
    }
    double St = sum(differenceInSquareVector.begin(), differenceInSquareVector.end());
    m_factorMap[Factor::sumOfsquaresOfDeviations] = St;
    return St;
}

double Accuracy::standardErrorOfEstymation(const std::pair<double, double> p_factors, signed p_sizeOfArray)
{
    QVector<double> differenceInSquareVector; // (yi - a0 - a1xi)^2
    for(signed i = 0; i < p_sizeOfArray; i++)
    {
        double dupa = m_lnFromSevered->getVectorOfSevered()[i] - p_factors.first - (p_factors.second * m_vectorOfResultX[i]);
        differenceInSquareVector.append(std::pow(dupa, 2.0));
    }

    double Sr = sum(differenceInSquareVector.begin(), differenceInSquareVector.end());
    m_factorMap[Factor::standardErrorOfEstymation] = Sr;
    return Sr;
}

double Accuracy::standardDeviationForRegresionLine(double p_standardErrorOfEstymation, double p_sizeOfArray)
{
    double Syx = std::sqrt(p_standardErrorOfEstymation/(p_sizeOfArray - 2));
    m_factorMap[Factor::standardDeviationForRegresionLine] = Syx;
    return Syx;
}




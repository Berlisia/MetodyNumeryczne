#include "Accuracy.h"
#include "Lnfromvalues.h"
#include "Linearyzator.h"
#include <cmath>

Accuracy::Accuracy(const QVector<double>& p_vectorOfResultY, const QVector<double>& p_vectorOfResultX) :
    m_vectorOfResultY(p_vectorOfResultY),
    m_vectorOfResultX(p_vectorOfResultX)
{
}

void Accuracy::calculateAccuracyOfLinearRegresion(const std::pair<double, double> p_factors)
{
    m_lnFromSevered = std::make_unique<LnFromValues>();
    m_lnFromSevered->calculateLn(m_vectorOfResultY);
    const signed l_numberOfElements = m_lnFromSevered->getVectorOfSevered().size();
    calculateAccuracyFactors(p_factors, l_numberOfElements);
}

std::map<Factor, double> Accuracy::getFactorMap()
{
    return m_factorMap;
}

void Accuracy::reset()
{
    m_lnFromSevered.reset(std::make_unique<LnFromValues>().get());
    m_factorMap.clear();
}

void Accuracy::calculateAccuracyFactors(const std::pair<double, double> p_factors, const double p_sizeOfArray)
{
    sumOfsquaresOfDeviations();
    standardDeviation(p_sizeOfArray);
    standardErrorOfEstymation(p_factors, p_sizeOfArray);
    standardDeviationForRegresionLine(p_sizeOfArray);
    correlatonCoefficient();
    coefficientOfdetermination();
}

void Accuracy::standardDeviation(const double p_sizeOfArray)
{
    double Sy = std::sqrt(m_factorMap[Factor::sumOfsquaresOfDeviations] / (p_sizeOfArray - 1));
    m_factorMap[Factor::standardDeviation] = Sy;
}

void Accuracy::sumOfsquaresOfDeviations()
{
    QVector<double> differenceInSquareVector = averageSquaredError();
    double St = sum(differenceInSquareVector.begin(), differenceInSquareVector.end());
    m_factorMap[Factor::sumOfsquaresOfDeviations] = St;
}

void Accuracy::standardErrorOfEstymation(const std::pair<double, double> p_factors, const signed p_sizeOfArray)
{
    QVector<double> differenceInSquareVector = squaredErrorWithFactors(p_factors, p_sizeOfArray); // (yi - a0 - a1xi)^2
    double Sr = sum(differenceInSquareVector.begin(), differenceInSquareVector.end());
    m_factorMap[Factor::standardErrorOfEstymation] = Sr;
}

void Accuracy::standardDeviationForRegresionLine(const double p_sizeOfArray)
{
    double Syx = std::sqrt(m_factorMap[Factor::standardErrorOfEstymation] / (p_sizeOfArray - 2));
    m_factorMap[Factor::standardDeviationForRegresionLine] = Syx;
}

void Accuracy::correlatonCoefficient()
{
    double r2 = (m_factorMap[Factor::sumOfsquaresOfDeviations] - m_factorMap[Factor::standardErrorOfEstymation])/
                                       m_factorMap[Factor::sumOfsquaresOfDeviations];
    m_factorMap[Factor::coefficientOfdetermination] = r2;
}

void Accuracy::coefficientOfdetermination()
{
    m_factorMap[Factor::correlationCoefficient] = std::sqrt(m_factorMap[Factor::coefficientOfdetermination]);
}

QVector<double> Accuracy::averageSquaredError()
{
    const double meanOfLnSevered = meanOfLnOfSevered();
    QVector<double> differenceInSquareVector; // (y - yśr)^2
    for(auto valueY : m_lnFromSevered->getVectorOfSevered())
    {
        differenceInSquareVector.append((std::pow(valueY - meanOfLnSevered, 2.0)));
    }
    return differenceInSquareVector;
}

QVector<double> Accuracy::squaredErrorWithFactors(const std::pair<double, double> p_factors, const signed p_sizeOfArray)
{
    QVector<double> differenceInSquareVector;
    for(signed i = 0; i < p_sizeOfArray; i++)
    {
        double value = m_lnFromSevered->getVectorOfSevered()[i] - std::log(p_factors.first) - (p_factors.second * m_vectorOfResultX[i]);
        differenceInSquareVector.append(std::pow(value, 2.0));
    }
    return differenceInSquareVector;
}

double Accuracy::meanOfLnOfSevered()
{
    const double meanOfLnSevered = mean(m_lnFromSevered->getVectorOfSevered().begin(), //y średnia
                                        m_lnFromSevered->getVectorOfSevered().end());
    return meanOfLnSevered;
}




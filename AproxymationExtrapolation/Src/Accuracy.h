#ifndef ACCURACY_H
#define ACCURACY_H
#include <memory>
#include <map>
#include "ILnFromValues.h"

enum class Factor
{
    sumOfsquaresOfDeviations,              // St
    standardDeviation,                     // Sy
    standardErrorOfEstymation,             // Sr
    standardDeviationForRegresionLine,     // Sy/x
    coefficientOfdetermination,            // r^2
    correlationCoefficient                 // r
};

class Accuracy
{
public:
    Accuracy(const QVector<double>& p_vectorOfResultY, const QVector<double>& p_vectorOfResultX);

    void calculateAccuracyOfLinearRegresion(const std::pair<double, double> p_factors);
    std::map<Factor, double> getFactorMap();
    void reset();

private:
    void calculateAccuracyFactors(const std::pair<double, double> p_factors, const double p_sizeOfArray);
    void sumOfsquaresOfDeviations();
    void standardDeviation(const double p_sizeOfArray);
    void standardErrorOfEstymation(const std::pair<double, double> p_factors, const signed p_sizeOfArray);
    void standardDeviationForRegresionLine(const double p_sizeOfArray);
    void correlatonCoefficient();
    void coefficientOfdetermination();
    QVector<double> averageSquaredError();
    QVector<double> squaredErrorWithFactors(const std::pair<double, double> p_factors, const signed p_sizeOfArray);
    double meanOfLnOfSevered();

    std::unique_ptr<ILnFromValues> m_lnFromSevered;
    const QVector<double>& m_vectorOfResultY;
    const QVector<double>& m_vectorOfResultX;
    std::map<Factor, double> m_factorMap;

};



#endif // ACCURACY_H

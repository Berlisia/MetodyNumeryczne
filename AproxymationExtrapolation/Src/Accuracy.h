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
private:
    double sumOfsquaresOfDeviations();
    double standardDeviation(double p_sumOfsquaresOfDeviations, double p_sizeOfArray);
    double standardErrorOfEstymation(const std::pair<double, double> p_factors, signed p_sizeOfArray);
    double standardDeviationForRegresionLine(double p_standardErrorOfEstymation, double p_sizeOfArray);

    std::unique_ptr<ILnFromValues> m_lnFromSevered;
    const QVector<double>& m_vectorOfResultY;
    const QVector<double>& m_vectorOfResultX;

    std::map<Factor, double> m_factorMap;

};



#endif // ACCURACY_H

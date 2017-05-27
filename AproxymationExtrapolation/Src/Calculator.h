#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <memory>
#include <utility>
#include <QVector>
#include "ILnFromValues.h"
#include "ILinearyzator.h"
#include "Accuracy.h"

class DataBase;

class Calculator
{
public:
    Calculator(const DataBase& p_dataBase);

    std::pair<double, double> calculate();
    const QVector<double> getVectorOfResultY();
    const QVector<double> getVectorOfResultX();
    std::map<Factor, double> getResultOfFactors();
    double calculateValueFromX();
    void reset();
private:
    void calculateResults(std::pair<double, double> p_factors);
    void calculateAccuracy();

    const DataBase& m_dataBase;
    std::unique_ptr<ILnFromValues> m_lnFromSevered;
    std::unique_ptr<ILinearyzator> m_linearyzator;

    QVector<double> m_vectorOfResultY;
    QVector<double> m_vectorOfResultX;
    std::pair<double, double> m_factors;
    Accuracy m_accuracy;
};

#endif // CALCULATOR_H

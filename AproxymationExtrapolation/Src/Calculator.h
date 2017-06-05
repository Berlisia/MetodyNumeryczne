#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <memory>
#include <utility>
#include <QVector>
#include "ILnFromValues.h"
#include "ILinearyzator.h"
#include "Accuracy.h"

class DataBase;
typedef QVector<std::pair<double, double>> FunctionFactors;

class Calculator
{
public:
    Calculator(const DataBase& p_dataBase);

    FunctionFactors calculate();
    const QVector<double> getVectorOfResultY();
    const QVector<double> getVectorOfResultX();
    std::map<Factor, double> getResultOfFactors();
    double calculateValueFromX(double p_valueX);
    void reset();
private:
    void calculateResults(std::pair<double, double> p_factors);
    void calculateAccuracy();
    void findCompartments(); //Przedziały
    const QVector<double> prepareCompartments();

    const DataBase& m_dataBase;
    //std::unique_ptr<ILnFromValues> m_lnFromSevered;
    std::vector<int> m_compartments;

    QVector<double> m_vectorOfResultY;
    QVector<double> m_vectorOfResultX;
    FunctionFactors m_factors;
    Accuracy m_accuracy;
};

#endif // CALCULATOR_H

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
typedef QVector<std::pair<int, int>> Compartments;
typedef QVector<std::map<Factor, double>> AccuracyFactors;

class Calculator
{
public:
    Calculator(const DataBase& p_dataBase);

    FunctionFactors calculate();
    const QVector<double> getVectorOfResultY();
    const QVector<double> getVectorOfResultX();
    AccuracyFactors getResultOfFactors();
    const Compartments getCompartments();
    void reset();
private:
    void calculateResults(std::pair<double, double> p_factors, int begin, int end);
    void calculateAccuracy();
    void findCompartments(); //Przedziały

    const DataBase& m_dataBase;
    Compartments m_compartments;
    QVector<double> m_vectorOfResultY;
    QVector<double> m_vectorOfResultX;
    FunctionFactors m_factors;
    AccuracyFactors m_accuracyFactors;
};

#endif // CALCULATOR_H

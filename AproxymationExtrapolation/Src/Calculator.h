#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <memory>
#include <utility>
#include <QVector>
#include "ILnFromValues.h"
#include "ILinearyzator.h"

class DataBase;

class Calculator
{
public:
    Calculator(const DataBase& p_dataBase);

    std::pair<float,float> calculate();
    QVector<float>& getVectorOfResultY();
    QVector<float>& getVectorOfResultX();
private:
    void calculateResults(std::pair<float, float> p_factors);

    const DataBase& m_dataBase;
    std::unique_ptr<ILnFromValues> m_lnFromSevered;
    std::unique_ptr<ILinearyzator> m_linearyzator;

    QVector<float> m_vectorOfResultY;
    QVector<float> m_vectorOfResultX;
};

#endif // CALCULATOR_H

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <memory>
#include <utility>

class ILnFromValues;
class ILinearyzator;
class DataBase;

class Calculator
{
public:
    Calculator(const DataBase& p_dataBase);

    std::pair<float,float> calculate();
private:
    std::unique_ptr<ILnFromValues> m_lnFromSevered;
    std::unique_ptr<ILinearyzator> m_linearyzator;
};

#endif // CALCULATOR_H

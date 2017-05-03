#include "Calculator.h"
#include "Lnfromvalues.h"
#include "DataBase.h"
#include "Linearyzator.h"

Calculator::Calculator(const DataBase& p_dataBase)
{
    m_lnFromSevered = std::make_unique<LnFromValues>(p_dataBase.getVectorOfSevered());
    m_linearyzator = std::make_unique<Linearyzator>(p_dataBase.getVectorOfOrdinates(),
                                                    *m_lnFromSevered.get());
}

std::pair<float, float> Calculator::calculate()
{
    return m_linearyzator->calculateFactors();
}

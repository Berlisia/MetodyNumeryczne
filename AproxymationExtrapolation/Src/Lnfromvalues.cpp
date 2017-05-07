#include "Lnfromvalues.h"
#include <cmath>

using namespace std;

const QVector<double> LnFromValues::getVectorOfSevered() const
{
    return m_vectorOfLnSevered;
}

void LnFromValues::calculateLn(const QVector<double>& p_vectorOfValues)
{
    for(auto value : p_vectorOfValues)
    {
        m_vectorOfLnSevered.append(log(value));
    }
}

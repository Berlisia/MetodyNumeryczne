#include "Lnfromvalues.h"
#include <cmath>

using namespace std;

const std::vector<float> &LnFromValues::getVectorOfSevered() const
{
    return m_vectorOfLnSevered;
}

void LnFromValues::calculateLn(const std::vector<float>& p_vectorOfValues)
{
    for(auto value : p_vectorOfValues)
    {
        m_vectorOfLnSevered.push_back(log(value));
    }
}

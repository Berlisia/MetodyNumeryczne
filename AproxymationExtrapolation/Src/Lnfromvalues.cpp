#include "Lnfromvalues.h"
#include <cmath>

using namespace std;

const std::vector<float> &LnFromValues::getVectorOfSevered() const
{
    return m_vectorOfLnSevered;
}

void LnFromValues::calculateLn(const std::vector<float>& p_vectorOfSevered)
{
    for(auto value : p_vectorOfSevered)
    {
        m_vectorOfLnSevered.push_back(log(value));
    }
}

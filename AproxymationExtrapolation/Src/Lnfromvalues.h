#ifndef LNFROMVALUES_H
#define LNFROMVALUES_H

#include <vector>
#include "ILnFromValues.h"

class LnFromValues : public ILnFromValues
{
public:
    LnFromValues(const std::vector<float>& p_vectorOfValues)
    {
        calculateLn(p_vectorOfValues);
    }

    const std::vector<float>& getVectorOfSevered() const override;
private:
    void calculateLn(const std::vector<float> &getVectorOfSevered);

    std::vector<float> m_vectorOfLnSevered;
};

#endif // LNFROMVALUES_H

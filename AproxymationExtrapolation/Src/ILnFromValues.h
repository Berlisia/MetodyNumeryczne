#ifndef ILNFROMVALUES_H
#define ILNFROMVALUES_H
#include <vector>

class ILnFromValues
{
public:
    virtual const std::vector<float>& getVectorOfSevered() const = 0;
};

#endif // ILNFROMVALUES_H

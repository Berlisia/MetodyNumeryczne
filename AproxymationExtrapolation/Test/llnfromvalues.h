#ifndef LLNFROMVALUES_H
#define LLNFROMVALUES_H
#include <gmock/gmock.h>
#include "Src/ILnFromValues.h"

class LnFromValuesMock : public ILnFromValues
{
public:
    MOCK_CONST_METHOD0(getVectorOfSevered, const QVector<double>());
};

#endif // LLNFROMVALUES_H

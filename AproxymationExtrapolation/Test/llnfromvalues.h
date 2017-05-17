#ifndef LLNFROMVALUES_H
#define LLNFROMVALUES_H
#include <gmock/gmock.h>
#include "Src/ILnFromValues.h"

class LnFromValuesMock : public ILnFromValues
{
public:
    MOCK_CONST_METHOD0(getVectorOfSevered, const QVector<double>());
    MOCK_METHOD1(calculateLn, void(const QVector<double> &p_vectorOfValues));
};

#endif // LLNFROMVALUES_H

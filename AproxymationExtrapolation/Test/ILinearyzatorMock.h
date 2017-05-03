#ifndef ILINEARYZATORMOCK_H
#define ILINEARYZATORMOCK_H
#include <gmock/gmock.h>
#include "Src/ILinearyzator.h"

class ILinearyzatorMock : public ILinearyzator
{
public:
    MOCK_METHOD0(calculateFactors, std::pair<float,float>());
};

#endif // ILINEARYZATORMOCK_H

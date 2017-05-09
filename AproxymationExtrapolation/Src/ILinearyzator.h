#ifndef ILINEARYZATOR_H
#define ILINEARYZATOR_H
#include <utility>
#include <numeric>
#include <cassert>
#include <iterator>

class ILinearyzator
{
public:
    virtual std::pair<double,double> calculateFactors() = 0;
};

#endif // ILINEARYZATOR_H

#ifndef ILINEARYZATOR_H
#define ILINEARYZATOR_H
#include <utility>
#include <numeric>
#include <cassert>
#include <iterator>

class ILinearyzator
{
public:
    virtual std::pair<float,float> calculateFactors() = 0;
};

template <typename It>
float average(It begin, It end)
{
    assert(begin != end);
    float s = std::accumulate(begin, end, 0.0);
    return s / std::distance(begin, end);
}

#endif // ILINEARYZATOR_H

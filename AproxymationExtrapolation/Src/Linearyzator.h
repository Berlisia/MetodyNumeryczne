#ifndef LINEARYZATOR_H
#define LINEARYZATOR_H

#include <vector>
#include <utility>
#include <numeric>
#include <cassert>

class ILnFromValues;

class Linearyzator
{
public:
    Linearyzator(const std::vector<float>& p_vectorOfOrdinates,
                 const ILnFromValues& p_vectorOfSevered)
        : m_vectorOfOrdinates(p_vectorOfOrdinates),
          m_vectorOfLnSevered(p_vectorOfSevered)
    {
    }

    std::pair<float,float> calculateFactors();
private:
    float calculateA1();
    float calculateA0(float factorA1);
    float sumOfMultiplicationXY();
    float sumOfX();
    float sumOfY();
    float sumOfX2();

    const std::vector<float>& m_vectorOfOrdinates; //X;
    const ILnFromValues& m_vectorOfLnSevered; //Y;
};

template <typename It>
auto average(It begin, It end)
{
    assert(begin != end);
    auto s = std::accumulate(begin, end, 0.0);
    return s / std::distance(begin, end);
}

#endif // LINEARYZATOR_H

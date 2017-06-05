#ifndef LINEARYZATOR_H
#define LINEARYZATOR_H

#include "ILinearyzator.h"
#include <QVector>

class ILnFromValues;

class Linearyzator : public ILinearyzator
{
public:
    Linearyzator(const QVector<double>& p_vectorOfOrdinates,
                 const QVector<double>& p_vectorOfSevered)
        : m_vectorOfOrdinates(p_vectorOfOrdinates),
          m_vectorOfLnSevered(p_vectorOfSevered)
    {}

    std::pair<double,double> calculateFactors() override;
private:
    double calculateA1();
    double calculateA0(const double factorA1);
    double sumOfMultiplicationXY();
    double sumOfX2();

    const QVector<double>& m_vectorOfOrdinates; //X;
    const QVector<double>& m_vectorOfLnSevered; //Y;
};

template<typename It>
auto sum(It begin, It end)
{
    auto sum = std::accumulate(begin, end, 0.0);
    return sum;
}

template<typename It>
auto mean(It begin, It end)
{
    auto mean = sum(begin, end) / static_cast<double>(std::distance(begin, end));
    return mean;
}

template<typename Vector>
auto ln(Vector p_vector)
{
    Vector l_vectorLnValues;
    for(auto value : p_vector)
    {
        l_vectorLnValues.append(log(value));
    }
    return l_vectorLnValues;
}

#endif // LINEARYZATOR_H

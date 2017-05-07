#ifndef LINEARYZATOR_H
#define LINEARYZATOR_H

#include "ILinearyzator.h"
#include <qvector>

class ILnFromValues;

class Linearyzator : public ILinearyzator
{
public:
    Linearyzator(const QVector<double>& p_vectorOfOrdinates,
                 const ILnFromValues& p_vectorOfSevered)
        : m_vectorOfOrdinates(p_vectorOfOrdinates),
          m_vectorOfLnSevered(p_vectorOfSevered)
    {
    }

    std::pair<float,float> calculateFactors() override;
private:
    float calculateA1();
    float calculateA0(const float factorA1);
    float sumOfMultiplicationXY();
    float sumOfX();
    float sumOfY();
    float sumOfX2();

    const QVector<double>& m_vectorOfOrdinates; //X;
    const ILnFromValues& m_vectorOfLnSevered; //Y;
};

#endif // LINEARYZATOR_H

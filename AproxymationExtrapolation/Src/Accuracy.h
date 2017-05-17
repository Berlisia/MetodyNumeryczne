#ifndef ACCURACY_H
#define ACCURACY_H
#include <memory>
#include "ILnFromValues.h"

class Accuracy
{
public:
    Accuracy(const QVector<double>& p_vectorOfResultY, const QVector<double>& p_vectorOfResultX);

    void calculateAccuracyOfLinearRegresion();
private:
    std::unique_ptr<ILnFromValues> m_lnFromSevered;
    const QVector<double>& m_vectorOfResultY;
    const QVector<double>& m_vectorOfResultX;



};

#endif // ACCURACY_H

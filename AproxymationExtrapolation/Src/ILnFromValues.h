#ifndef ILNFROMVALUES_H
#define ILNFROMVALUES_H
#include <QVector>

class ILnFromValues
{
public:
    virtual const QVector<double> getVectorOfSevered() const = 0;
    virtual void calculateLn(const QVector<double> &p_vectorOfValues) = 0;
};

#endif // ILNFROMVALUES_H

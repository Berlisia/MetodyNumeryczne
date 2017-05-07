#ifndef LNFROMVALUES_H
#define LNFROMVALUES_H

#include <vector>
#include "ILnFromValues.h"

class LnFromValues : public ILnFromValues
{
public:
    LnFromValues(const QVector<double>& p_vectorOfValues)
    {
        calculateLn(p_vectorOfValues);
    }

    const QVector<double> getVectorOfSevered() const override;
    void calculateLn(const QVector<double> &p_vectorOfValues) override;

private:
    QVector<double> m_vectorOfLnSevered;
};

#endif // LNFROMVALUES_H

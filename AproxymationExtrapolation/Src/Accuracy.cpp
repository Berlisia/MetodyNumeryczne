#include "Accuracy.h"
#include "Lnfromvalues.h"
#include "Linearyzator.h"

Accuracy::Accuracy(const QVector<double>& p_vectorOfResultY, const QVector<double>& p_vectorOfResultX) :
    m_vectorOfResultY(p_vectorOfResultY),
    m_vectorOfResultX(p_vectorOfResultX)
{
    m_lnFromSevered = std::make_unique<LnFromValues>();
}

void Accuracy::calculateAccuracyOfLinearRegresion()
{
    m_lnFromSevered->calculateLn(m_vectorOfResultY);
    double meanOfLnSevered = mean(m_lnFromSevered->getVectorOfSevered().begin(),
                                  m_lnFromSevered->getVectorOfSevered().end());
}


#include <gtest/gtest.h>
#include "Src/Accuracy.h"

namespace
{
    const QVector<double> vectorOfResultY{ 7.389818183263667,
                                           54.601531098901670,
                                           4.034371515521700e+02,
                                           2.980896908508170e+03};
    const QVector<double> vectorOfResultX{ 1,2,3,4};
    std::map<Factor, double> defaultFactorMap;
}

class AccuracyTestSuit : public testing::Test
{
public:
    AccuracyTestSuit() : m_sut(vectorOfResultY, vectorOfResultX)
    {
    }

    void SetUp()
    {
        setUpDefaultFactorMap();
    }
    Accuracy m_sut;

    void setUpDefaultFactorMap()
    {
        defaultFactorMap[Factor::sumOfsquaresOfDeviations] = 19.999175866116104;
        defaultFactorMap[Factor::standardDeviation] = 2.5819356993101192;
        defaultFactorMap[Factor::standardErrorOfEstymation] = 4.000000083338658;
        defaultFactorMap[Factor::standardDeviationForRegresionLine] = 1.4142135771054274;
        defaultFactorMap[Factor::coefficientOfdetermination] = 0.7999917541544441;
        defaultFactorMap[Factor::correlationCoefficient] = 0.894422581420239;
    }
};

TEST_F(AccuracyTestSuit, shouldCorrectFillFactors)
{
    const std::pair<double, double> l_factors{1.000144349116847, 1.999958792881299};
    m_sut.calculateAccuracyOfLinearRegresion(l_factors);
    std::map<Factor, double> l_map = m_sut.getFactorMap();

    EXPECT_EQ(defaultFactorMap[Factor::sumOfsquaresOfDeviations], l_map[Factor::sumOfsquaresOfDeviations]);
    EXPECT_EQ(defaultFactorMap[Factor::standardDeviation], l_map[Factor::standardDeviation]);
    EXPECT_EQ(defaultFactorMap[Factor::standardErrorOfEstymation], l_map[Factor::standardErrorOfEstymation]);
    EXPECT_EQ(defaultFactorMap[Factor::standardDeviationForRegresionLine], l_map[Factor::standardDeviationForRegresionLine]);
    EXPECT_EQ(defaultFactorMap[Factor::coefficientOfdetermination], l_map[Factor::coefficientOfdetermination]);
    EXPECT_EQ(defaultFactorMap[Factor::correlationCoefficient], l_map[Factor::correlationCoefficient]);
}

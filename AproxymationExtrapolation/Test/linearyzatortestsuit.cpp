#include <gtest/gtest.h>
#include "Src/Linearyzator.h"
#include "llnfromvalues.h"

using ::testing::Return;

namespace
{
const QVector<double> vectorOfValueY{7.39, 54.60, 403.43, 2980.96};
const QVector<double> vectorOfX{1,2,3,4};

const QVector<double> vectorOfLnY{2.000127734960111,
                                     4.000033882750859,
                                     6.000002990628037,
                                     8.000000675272045};

std::pair<double,double> linearyzationFactors(1.0001443491168518, //a
                                              1.9999587928812972); //b=a1
}

class LinearyzatorTestSuit : public testing::Test
{
public:
    LinearyzatorTestSuit() : m_sut(vectorOfX, m_lnValuesMock)
    {
    }

    void SetUp()
    {
        EXPECT_CALL(m_lnValuesMock, getVectorOfSevered())
                .WillRepeatedly(Return(vectorOfLnY));
    }

    LnFromValuesMock m_lnValuesMock;
    Linearyzator m_sut;
};

TEST_F(LinearyzatorTestSuit, shouldReturnFactorsOfLinearyzation)
{
    std::pair<double,double> l_factors = m_sut.calculateFactors();
    ASSERT_EQ(l_factors.first, linearyzationFactors.first);
    ASSERT_EQ(l_factors.second, linearyzationFactors.second);
}

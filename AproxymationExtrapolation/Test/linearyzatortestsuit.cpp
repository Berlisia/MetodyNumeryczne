#include <gtest/gtest.h>
#include "Src/Linearyzator.h"
#include "llnfromvalues.h"

using ::testing::ReturnRef;

namespace
{
const std::vector<float> vectorOfValueY{7.39, 54.60, 403.43, 2980.96};
const std::vector<float> vectorOfX{1,2,3,4};

const std::vector<float> vectorOfLnY{2.000127734960111,
                                     4.000033882750859,
                                     6.000002990628037,
                                     8.000000675272045};

std::pair<float,float> linearyzationFactors(1.0000414848327637, //a
                                            2.0); //b=a1
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
                .WillRepeatedly(ReturnRef(vectorOfLnY));
    }

    LnFromValuesMock m_lnValuesMock;
    Linearyzator m_sut;
};

TEST_F(LinearyzatorTestSuit, shouldReturnFactorsOfLinearyzation)
{
    std::pair<float,float> l_factors = m_sut.calculateFactors();
    ASSERT_EQ(l_factors.first, linearyzationFactors.first);
    ASSERT_EQ(l_factors.second, linearyzationFactors.second);
}

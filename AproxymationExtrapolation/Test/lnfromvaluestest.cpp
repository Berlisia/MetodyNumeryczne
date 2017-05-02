#include <gtest/gtest.h>
#include "Src/Lnfromvalues.h"

namespace
{
const std::vector<float> vectorOfValueY{7.39, 54.60, 403.43, 2980.96};
const std::vector<float> vectorOfX{1,2,3,4};

const std::vector<float> vectorOfLnY{2.000127734960111,
                                     4.000033882750859,
                                     6.000002990628037,
                                     8.000000675272045};
}

class LnFromValuesTestSuit : public testing::Test
{
public:
    LnFromValuesTestSuit() : sut(vectorOfValueY)
    {
    }

    LnFromValues sut;
};

TEST_F(LnFromValuesTestSuit, shouldCorrectReturnLnFromVectorOfValueY)
{
    const std::vector<float>& l_vector = sut.getVectorOfSevered();

    for(unsigned i = 0; i < l_vector.size(); i++)
    {
        ASSERT_EQ(l_vector[i], vectorOfLnY[i]);
    }
}

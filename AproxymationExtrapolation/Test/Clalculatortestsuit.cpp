//#include <gtest/gtest.h>
//#include "ILinearyzatorMock.h"
//#include "llnfromvalues.h"
//#include "databasemock.h"
//#include "Src/Calculator.h"

//using ::testing::ReturnRef;
//using ::testing::Return;

//namespace
//{
//const std::vector<float> vectorOfValueY{7.39, 54.60, 403.43, 2980.96};
//const std::vector<float> vectorOfX{1,2,3,4};

//const std::vector<float> vectorOfLnY{2.000127734960111,
//                                     4.000033882750859,
//                                     6.000002990628037,
//                                     8.000000675272045};

//std::pair<float,float> linearyzationFactors(1.0000414848327637, //a
//                                            2.0); //b=a1
//}

//class ClalculatorTestSuit : public testing::Test
//{
//public:
//    ClalculatorTestSuit() : m_sut(m_dataBaseMock)
//    {

//    }

//    void SetUp()
//    {
//        EXPECT_CALL(m_dataBaseMock, getVectorOfOrdinates())
//                .WillRepeatedly(ReturnRef(vectorOfX));
//        EXPECT_CALL(m_dataBaseMock, getVectorOfSevered())
//                .WillRepeatedly(ReturnRef(vectorOfValueY));
//        EXPECT_CALL(m_lnFromValuesMock, getVectorOfSevered())
//                .WillRepeatedly(ReturnRef(vectorOfLnY));
//        EXPECT_CALL(m_linearyatorMock, calculateFactors())
//                .WillRepeatedly(Return(linearyzationFactors));
//    }

//    DataBaseMock m_dataBaseMock;
//    LnFromValuesMock m_lnFromValuesMock;
//    ILinearyzatorMock m_linearyatorMock;

//    Calculator m_sut;
//};

//TEST_F(ClalculatorTestSuit, shouldWorkProperlyxD)
//{
//    m_sut.calculate();
//}

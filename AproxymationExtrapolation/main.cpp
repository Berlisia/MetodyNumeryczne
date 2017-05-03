#include <QApplication>
#include "App/mainwindow.h"
#include "Src/Controler.h"
//#include <gtest/gtest.h>

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

int main(int argc, char *argv[])
{
//    try
//    {
//        testing::InitGoogleTest( &argc, argv );
//        return RUN_ALL_TESTS();
//    }
//    catch ( ... )
//    {
//        return 0;
//    }
//    return 0;

    QApplication app(argc, argv);
    DataBase m_dataBase;
    for(auto i : vectorOfValueY)
    {
        m_dataBase.setDataOfSevered(i);
    }
    for(auto i : vectorOfX)
    {
        m_dataBase.setDataOfOrdinates(i);
    }
    Controler controler(m_dataBase);
    return app.exec();
}

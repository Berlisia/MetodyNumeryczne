#include <QApplication>
#include "App/mainwindow.h"
#include "Src/Controler.h"
//#include <gtest/gtest.h>
#include <fstream>
#include <cmath>

void generejdKupe()
{
    std::fstream l_file;
    l_file.open("Data.csv", std::ios::out);
    if(l_file.good())
    {
        int i = 0;
        while(i < 10000)
        {
            l_file << (double)i/100 << ";" << (0.5667 * std::exp(0.7777*i/100)) << std::endl;
            i = i + 1;
        }
        l_file.close();
    }
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
    generejdKupe();
    DataBase m_dataBase;
    MainWindow m_mainWindow(m_dataBase);
    Controler controler(m_dataBase, &m_mainWindow);
    return app.exec();

}

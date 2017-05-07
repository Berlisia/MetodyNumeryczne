#include <QApplication>
#include "App/mainwindow.h"
#include "Src/Controler.h"
//#include <gtest/gtest.h>

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
    MainWindow m_mainWindow(m_dataBase);
    Controler controler(m_dataBase, &m_mainWindow);
    return app.exec();
}

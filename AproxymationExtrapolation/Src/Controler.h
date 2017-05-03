#ifndef CONTROLER_H
#define CONTROLER_H
#include <QObject>
#include <memory>
#include "DataBase.h"
#include "Calculator.h"
#include "App/mainwindow.h"

class Controler
{
    //Q_OBJECT
public:
    Controler(DataBase& p_dataBase);

private:
    DataBase m_dataBase;
    Calculator m_calculator;
    MainWindow m_mainWindow;
};

#endif // CONTROLER_H

#ifndef CONTROLER_H
#define CONTROLER_H
#include <QObject>
#include <memory>
#include "DataBase.h"
#include "Calculator.h"
#include "App/mainwindow.h"

class Controler : public QObject
{
    Q_OBJECT

public:    
    Controler(DataBase& p_dataBase, MainWindow* p_mainWindow) :
        m_dataBase(p_dataBase),
        m_calculator(Calculator(p_dataBase)),
        m_mainWindow(p_mainWindow)
    {
        m_mainWindow->show();
        setConnections();
    }

private slots:
    void loadFile();
    void makeCalculation();

private:
    void setConnections();
    void drawPoints();

    DataBase& m_dataBase;
    Calculator m_calculator;
    MainWindow* m_mainWindow;
};

#endif // CONTROLER_H

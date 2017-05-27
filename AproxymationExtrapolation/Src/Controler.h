#ifndef CONTROLER_H
#define CONTROLER_H
#include <QObject>
#include <memory>
#include "DataBase.h"
#include "Calculator.h"
#include "App/mainwindow.h"
#include "FileParser.h"

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
    void clearData();
    void tryClear();
    void setPointsToChart();
    std::pair<double, double> claculate();
    void showResultOfCalculation(std::pair<double, double> p_factors);

    DataBase& m_dataBase;
    Calculator m_calculator;
    MainWindow* m_mainWindow;
    FileParser m_fileParser;
    bool m_shouldClear = false;
};

#endif // CONTROLER_H

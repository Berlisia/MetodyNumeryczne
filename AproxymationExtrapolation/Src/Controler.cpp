#include "Controler.h"

void Controler::loadFile()
{
    tryClear();
    if(m_fileParser.loadFileTo(m_dataBase))
    {
        setPointsToChart();
    }
}

void Controler::makeCalculation()
{
    if(m_dataBase.checkHasData())
    {
        showResultOfCalculation(claculateFactors());
    }
}

void Controler::calculateValueY(double p_valueX)
{
    double valueY = m_calculator.calculateValueFromX(p_valueX);
    m_mainWindow->showValueYFromValueX(valueY);
}

void Controler::setConnections()
{
    connect(m_mainWindow, SIGNAL(applyNewFile()), this, SLOT(loadFile()));
    connect(m_mainWindow, SIGNAL(calculatePressed()), this, SLOT(makeCalculation()));
    connect(&m_fileParser, SIGNAL(fileError()), m_mainWindow, SLOT(showFileError()));
    connect(m_mainWindow, SIGNAL(YValueTriggered(double)), this, SLOT(calculateValueY(double)));
}

void Controler::clearData()
{
    m_dataBase.clearDataBase();
    m_mainWindow->clear();
    m_calculator.reset();
}

void Controler::tryClear()
{
    if(m_shouldClear)
        clearData();
}

void Controler::setPointsToChart()
{
    //m_mainWindow->showFileOk();
    m_mainWindow->setInputPoints(m_dataBase.getVectorOfOrdinates(), m_dataBase.getVectorOfSevered());
    m_shouldClear = true;
}

std::pair<double, double> Controler::claculateFactors()
{
    std::pair<double, double> l_factors = m_calculator.calculate();
    return l_factors;
}

void Controler::showResultOfCalculation(std::pair<double, double> p_factors)
{
    m_mainWindow->showFactors(p_factors);
    m_mainWindow->setResult(m_calculator.getVectorOfResultX(), m_calculator.getVectorOfResultY());
    m_mainWindow->showAccuracyFactors(m_calculator.getResultOfFactors());
}


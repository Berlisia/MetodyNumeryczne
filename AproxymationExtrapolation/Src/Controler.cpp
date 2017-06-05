#include "Controler.h"

void Controler::loadFile()
{
    tryClear();
    if(m_fileParser.loadFileTo(m_dataBase))
    {
        setPointsToChart();
    }
    //TODO sortowanie po x
}

void Controler::makeCalculation()
{
    if(m_dataBase.checkHasData())
    {
        claculateFactors();
        showResultOfCalculation();
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
    m_mainWindow->setInputPoints(m_dataBase.getVectorOfOrdinates(), m_dataBase.getVectorOfSevered());
    m_shouldClear = true;
}

void Controler::claculateFactors()
{
    FunctionFactors l_factors = m_calculator.calculate();
    //return l_factors;
}

void Controler::showResultOfCalculation()//FunctionFactors /*p_factors*/)
{
    //m_mainWindow->showFactors(p_factors);
    m_mainWindow->setResult(m_calculator.getVectorOfResultX(), m_calculator.getVectorOfResultY());
    m_mainWindow->showAccuracyFactors(m_calculator.getResultOfFactors());
}


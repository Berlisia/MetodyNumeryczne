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

void Controler::setConnections()
{
    connect(m_mainWindow, SIGNAL(applyNewFile()), this, SLOT(loadFile()));
    connect(m_mainWindow, SIGNAL(calculatePressed()), this, SLOT(makeCalculation()));
    connect(&m_fileParser, SIGNAL(fileError()), m_mainWindow, SLOT(showFileError()));
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

FunctionFactors Controler::claculateFactors()
{
    FunctionFactors l_factors = m_calculator.calculate();
    return l_factors;
}

void Controler::showResultOfCalculation(const FunctionFactors& p_factors)
{
    m_mainWindow->showFactors(p_factors, m_calculator.getCompartments());
    m_mainWindow->setResult(m_calculator.getVectorOfResultX(), m_calculator.getVectorOfResultY());
    m_mainWindow->showAccuracyFactors(m_calculator.getResultOfFactors(), m_calculator.getCompartments());
}


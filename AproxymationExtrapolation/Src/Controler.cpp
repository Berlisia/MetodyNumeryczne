#include "Controler.h"

void Controler::loadFile()
{
    if(m_fileParser.loadFileTo(m_dataBase))
    {
        m_mainWindow->showFileOk();
        m_mainWindow->setInputPoints(m_dataBase.getVectorOfOrdinates(), m_dataBase.getVectorOfSevered());
    }
}

void Controler::makeCalculation()
{
    std::pair<double, double> l_factors = m_calculator.calculate();
    m_mainWindow->showFactors(l_factors);
    m_mainWindow->setResult(m_calculator.getVectorOfResultX(), m_calculator.getVectorOfResultY());
}

void Controler::setConnections()
{
    connect(m_mainWindow, SIGNAL(applyNewFile()), this, SLOT(loadFile()));
    connect(m_mainWindow, SIGNAL(calculatePressed()), this, SLOT(makeCalculation()));
    connect(&m_fileParser, SIGNAL(fileError()), m_mainWindow, SLOT(showFileError()));
}


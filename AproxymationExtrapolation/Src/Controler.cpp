#include "Controler.h"
#include <fstream>

void Controler::loadFile()
{
    std::fstream l_file;
    l_file.open(m_dataBase.getFileName(), std::ios::in);
    if(l_file.good())
    {
        std::string l_valueXBuff{""};
        std::string l_valueYBuff{""};
        while(!l_file.eof())
        {
            getline(l_file, l_valueXBuff,';');
            getline(l_file, l_valueYBuff);
            const float l_valueX = stof(l_valueXBuff);
            const float l_valueY = stof(l_valueYBuff);
            m_dataBase.setDataOfOrdinates(l_valueX);
            m_dataBase.setDataOfSevered(l_valueY);
        }
        l_file.close();
        m_mainWindow->showFileOk();
        m_mainWindow->setInputPoints(m_dataBase.getVectorOfOrdinates(), m_dataBase.getVectorOfSevered());
    }
    else
        m_mainWindow->showFileError();
}

void Controler::makeCalculation()
{
    std::pair<float, float> l_factors = m_calculator.calculate();
    m_mainWindow->showFactors(l_factors);
    m_mainWindow->setResult(m_calculator.getVectorOfResultX(), m_calculator.getVectorOfResultY());
}

void Controler::setConnections()
{
    connect(m_mainWindow, SIGNAL(applyNewFile()), this, SLOT(loadFile()));
    connect(m_mainWindow, SIGNAL(calculatePressed()), this, SLOT(makeCalculation()));
}


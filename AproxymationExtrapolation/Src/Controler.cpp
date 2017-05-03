#include "Controler.h"

Controler::Controler(DataBase &p_dataBase) : m_dataBase(p_dataBase),
    m_calculator(Calculator(p_dataBase))
{
    m_calculator.calculate();


    m_mainWindow.show();
    m_mainWindow.setResult(m_calculator.getVectorOfResultX(), m_calculator.getVectorOfResultY());
}


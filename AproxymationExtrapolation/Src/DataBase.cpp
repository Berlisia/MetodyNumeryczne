#include "DataBase.h"

void DataBase::setDataOfOrdinates(const double p_X)
{
    m_vectorOfOrdinates.append(p_X);
}

void DataBase::setDataOfSevered(const double p_Y)
{
    m_vectorOfSevered.append(p_Y);
}

void DataBase::setDataFileName(QString p_name)
{
    m_dataFileName = p_name;
}

const QVector<double>& DataBase::getVectorOfOrdinates() const
{
    return m_vectorOfOrdinates;
}

const QVector<double>& DataBase::getVectorOfSevered() const
{
    return m_vectorOfSevered;
}

QString DataBase::getFileName()
{
    return m_dataFileName;
}

void DataBase::clearDataBase()
{
    m_vectorOfOrdinates.clear();
    m_vectorOfSevered.clear();
    m_dataFileName.clear();
}

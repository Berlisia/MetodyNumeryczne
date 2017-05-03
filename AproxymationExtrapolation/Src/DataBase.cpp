#include "DataBase.h"

void DataBase::setDataOfOrdinates(const float p_X)
{
    m_vectorOfOrdinates.push_back(p_X);
}

void DataBase::setDataOfSevered(const float p_Y)
{
    m_vectorOfSevered.push_back(p_Y);
}

const std::vector<float>& DataBase::getVectorOfOrdinates() const
{
    return m_vectorOfOrdinates;
}

const std::vector<float>& DataBase::getVectorOfSevered() const
{
    return m_vectorOfSevered;
}

void DataBase::clearDataBase()
{
    m_vectorOfOrdinates.clear();
    m_vectorOfSevered.clear();
}

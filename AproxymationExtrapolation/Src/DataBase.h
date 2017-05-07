#ifndef DATABASE_H
#define DATABASE_H
#include <qvector>
#include <string>

class DataBase
{
public:    
    void setDataOfOrdinates(const double p_X);
    void setDataOfSevered(const double p_Y);
    void setDataFileName(std::string p_name);

    const QVector<double>& getVectorOfOrdinates() const;
    const QVector<double>& getVectorOfSevered() const;
    std::string getFileName();

    void clearDataBase();
private:
    QVector<double> m_vectorOfOrdinates; //X
    QVector<double> m_vectorOfSevered; //Y

    std::string m_dataFileName;
};

#endif // DATABASE_H

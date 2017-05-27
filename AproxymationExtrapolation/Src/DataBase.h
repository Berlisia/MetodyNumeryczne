#ifndef DATABASE_H
#define DATABASE_H
#include <QVector>
#include <string>

class DataBase
{
public:    
    void setDataOfOrdinates(const double p_X);
    void setDataOfSevered(const double p_Y);
    void setDataFileName(QString p_name);

    const QVector<double>& getVectorOfOrdinates() const;
    const QVector<double>& getVectorOfSevered() const;
    QString getFileName();
    bool checkHasData();

    void clearDataBase();
private:
    QVector<double> m_vectorOfOrdinates; //X
    QVector<double> m_vectorOfSevered; //Y
    QString m_dataFileName;
};

#endif // DATABASE_H

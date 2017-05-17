#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <QVector>
#include <string>
#include <QObject>

class DataBase;
class QFile;

class FileParser : public QObject
{
     Q_OBJECT
public:
    bool loadFileTo(DataBase& p_dataBase);

signals:
    void fileError();
private:
    void applyData(QFile *p_file, DataBase& p_dataBase);
};

#endif // FILEPARSER_H

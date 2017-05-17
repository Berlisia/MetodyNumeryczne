#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <QVector>
#include <string>
#include <QObject>

class DataBase;

class FileParser : public QObject
{
     Q_OBJECT
public:
    bool loadFileTo(DataBase & p_dataBase);

signals:
    void fileError();
    void fileDone();
};

#endif // FILEPARSER_H

#include "FileParser.h"
#include "DataBase.h"
#include <QFile>
#include <QString>
#include <QTextStream>

bool FileParser::loadFileTo(DataBase & p_dataBase)
{
    QFile l_file(p_dataBase.getFileName());
    if(!l_file.open(QFile::ReadOnly | QFile::Text))
    {
        emit fileError();
        return false;
    }
    applyData(&l_file, p_dataBase);
    return true;
}

void FileParser::applyData(QFile* p_file, DataBase& p_dataBase)
{
    QTextStream in(p_file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList list = line.split(";");
        p_dataBase.setDataOfOrdinates(list[0].toDouble());
        p_dataBase.setDataOfSevered(list[1].toDouble());
    }
    p_file->close();
}

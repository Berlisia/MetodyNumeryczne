#include "FileParser.h"
#include "DataBase.h"
#include <fstream>

bool FileParser::loadFileTo(DataBase & p_dataBase)
{
    bool l_done = false;
    std::fstream l_file;
    l_file.open(p_dataBase.getFileName(), std::ios::in);
    if(l_file.good())
    {
        std::string l_valueXBuff{""};
        std::string l_valueYBuff{""};
        while(!l_file.eof())
        {
            getline(l_file, l_valueXBuff,';');
            getline(l_file, l_valueYBuff);
            const double l_valueX = stof(l_valueXBuff);
            const double l_valueY = stof(l_valueYBuff);
            p_dataBase.setDataOfOrdinates(l_valueX);
            p_dataBase.setDataOfSevered(l_valueY);
        }
        l_file.close();
        l_done = true;
    }
    else
    {
        emit fileError();
    }
    return l_done;
}

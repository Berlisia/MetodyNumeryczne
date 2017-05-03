#ifndef DATABASE_H
#define DATABASE_H
#include <vector>

class DataBase
{
public:    
    void setDataOfOrdinates(const float p_X);
    void setDataOfSevered(const float p_Y);

    const std::vector<float>& getVectorOfOrdinates() const;
    const std::vector<float>& getVectorOfSevered() const;

    void clearDataBase();
private:
    std::vector<float> m_vectorOfOrdinates; //X
    std::vector<float> m_vectorOfSevered; //Y
};

#endif // DATABASE_H

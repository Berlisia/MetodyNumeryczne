#ifndef DATABASEMOCK_H
#define DATABASEMOCK_H
#include <gmock/gmock.h>
#include "Src/DataBase.h"

class DataBaseMock : public DataBase
{
public:
    MOCK_METHOD1(setDataOfOrdinates, void(const float));
    MOCK_METHOD1(setDataOfSevered, void(const float));
    MOCK_CONST_METHOD0(getVectorOfOrdinates, const QVector<double>&());
    MOCK_CONST_METHOD0(getVectorOfSevered, const QVector<double>&());
    MOCK_METHOD0(clearDataBase, void());
};

#endif // DATABASEMOCK_H

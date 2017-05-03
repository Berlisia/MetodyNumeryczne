#-------------------------------------------------
#
# Project created by QtCreator 2017-05-01T15:40:11
#
#-------------------------------------------------

QT       += core gui
CONFIG += console c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -lgtest -L/usr/lib
LIBS += -lgmock -L/usr/lib -lpthread

TARGET = AproxymationExtrapolation
TEMPLATE = app


SOURCES += main.cpp\
    App/mainwindow.cpp \
    Src/Calculator.cpp \
    Src/Linearyzator.cpp \
    Src/Lnfromvalues.cpp \
    Test/lnfromvaluestest.cpp \
    Test/linearyzatortestsuit.cpp \
    Src/DataBase.cpp \
    Test/Clalculatortestsuit.cpp \
    Src/Accuracy.cpp \
    Src/qcustomplot.cpp

HEADERS  += App/mainwindow.h \
    Src/Calculator.h \
    Src/Linearyzator.h \
    Src/Lnfromvalues.h \
    Test/llnfromvalues.h \
    Src/ILnFromValues.h \
    Src/ILinearyzator.h \
    Src/DataBase.h \
    Test/ILinearyzatorMock.h \
    Test/databasemock.h \
    Src/Accuracy.h \
    Src/qcustomplot.h

FORMS    += mainwindow.ui

#-------------------------------------------------
#
# Project created by QtCreator 2017-05-01T15:40:11
#
#-------------------------------------------------

QT       += core gui
CONFIG += console c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += printsupport

#LIBS += -lgtest -L/usr/lib
#LIBS += -lgmock -L/usr/lib -lpthread

TARGET = AproxymationExtrapolation
TEMPLATE = app

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
#QMAKE_CXXFLAGS_RELEASE -= -O2

SOURCES += main.cpp\
    App/mainwindow.cpp \
    Src/Calculator.cpp \
    Src/Linearyzator.cpp \
    Src/Lnfromvalues.cpp \
#    Test/lnfromvaluestest.cpp \
#    Test/linearyzatortestsuit.cpp \
    Src/DataBase.cpp \
#    Test/Clalculatortestsuit.cpp \
    Src/Accuracy.cpp \
    Src/qcustomplot.cpp \
    Src/Controler.cpp \
    Src/FileParser.cpp \
#    Test/AccuracyTestSuit.cpp
    App/ChartViewer.cpp

HEADERS  += App/mainwindow.h \
    Src/Calculator.h \
    Src/Linearyzator.h \
    Src/Lnfromvalues.h \
#    Test/llnfromvalues.h \
    Src/ILnFromValues.h \
    Src/ILinearyzator.h \
    Src/DataBase.h \
#    Test/ILinearyzatorMock.h \
#    Test/databasemock.h \
    Src/Accuracy.h \
    Src/qcustomplot.h \
    Src/Controler.h \
    Src/FileParser.h \
    App/ChartViewer.h

FORMS    += mainwindow.ui \
    App/ChartViewer.ui

RESOURCES += \
    resources.qrc

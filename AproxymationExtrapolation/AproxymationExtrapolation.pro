#-------------------------------------------------
#
# Project created by QtCreator 2017-05-01T15:40:11
#
#-------------------------------------------------

QT       += core gui
CONFIG += console c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += GTEST_LINKED_AS_SHARED_LIBRARY=1

LIBS += -lgtest -L/usr/lib/

TARGET = AproxymationExtrapolation
TEMPLATE = app


SOURCES += main.cpp\
    App/mainwindow.cpp \
    Src/Calculator.cpp \
    Src/Linearyzator.cpp \
    Src/Lnfromvalues.cpp \
    Test/lnfromvaluestest.cpp \
    Test/linearyzatortestsuit.cpp

HEADERS  += App/mainwindow.h \
    Src/Calculator.h \
    Src/Linearyzator.h \
    Src/Lnfromvalues.h \
    Test/linearyzatormock.h \
    Test/llnfromvalues.h \
    Src/ILnFromValues.h

FORMS    += mainwindow.ui

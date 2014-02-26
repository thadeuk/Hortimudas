#-------------------------------------------------
#
# Project created by QtCreator 2014-02-04T23:24:43
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hortimudas-new
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    customer.cpp \
    dbmanager.cpp

HEADERS  += mainwindow.h \
    customer.h \
    dbmanager.h

FORMS    += mainwindow.ui \
    customer.ui

RESOURCES += \
    icons.qrc

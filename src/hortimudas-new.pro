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
    dbmanager.cpp \
    supplier.cpp \
    accounts_receivable.cpp \
    accounts_payable.cpp

HEADERS  += mainwindow.h \
    customer.h \
    dbmanager.h \
    supplier.h \
    accounts_receivable.h \
    accounts_payable.h

FORMS    += mainwindow.ui \
    customer.ui \
    supplier.ui \
    accounts_receivable.ui \
    accounts_payable.ui

RESOURCES += \
    icons.qrc

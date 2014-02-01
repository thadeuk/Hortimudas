#-------------------------------------------------
#
# Project created by QtCreator 2012-06-15T22:57:20
#
#-------------------------------------------------

QT       += core gui sql widgets

TARGET = hortiqt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbmanager.cpp \
    cadastracliente.cpp \
    cadastrafornecedor.cpp \
    cadastrafornecedor2.cpp \
    cadastracliente2.cpp \
    pagar/cadastracontaspagar.cpp \
    pagar/listafornecedores.cpp


HEADERS  += mainwindow.h \
    dbmanager.h \
    cadastracliente.h \
    cadastrafornecedor.h \
    cadastrafornecedor2.h \
    cadastracliente2.h \
    pagar/cadastracontaspagar.h \
    pagar/listafornecedores.h


FORMS    += mainwindow.ui \
    cadastracliente.ui \
    cadastrafornecedor.ui \
    cadastrafornecedor2.ui \
    cadastracliente2.ui \
    pagar/cadastracontaspagar.ui \
    pagar/listafornecedores.ui


RESOURCES += \
    icons/icons.qrc

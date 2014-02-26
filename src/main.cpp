#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <dbmanager.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();

    DBManager db;
    if (!db.openDB()) {
        QMessageBox::critical(0, "Base de dados", "Não foi possível conectar ao banco de dados\n"
                              "Entre em contato com o desenvolvedor", QMessageBox::Cancel);
        return false;
    }

    return a.exec();
}

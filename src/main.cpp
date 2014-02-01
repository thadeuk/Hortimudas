
#include <QtWidgets>
#include <QtSql>
#include "mainwindow.h"
#include "dbmanager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    
    DBManager db;
    if (!db.openDB()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
         qApp->tr("Unable to establish a database connection.\n"
                  "This example needs SQLite support. Please read "
                  "the Qt SQL driver documentation for information how "
                  "to build it.\n\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    return a.exec();
}

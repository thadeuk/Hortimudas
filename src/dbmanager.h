#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#ifndef DBMANAGER_H
#define DBMANAGER_H

class DBManager
{
    public:
        bool openDB();
        QSqlError lastError();
        bool createPersonTable();
        ~DBManager();

    private:
        QSqlDatabase db;
};


#endif // DBMANAGER_H

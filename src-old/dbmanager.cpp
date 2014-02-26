#include "dbmanager.h"

bool DBManager::openDB()
{
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dbsqlite");
    // Open databasee
    return db.open();
}

QSqlError DBManager::lastError()
{
    // If opening database has failed user can ask
    // error description by QSqlError::text()
    return db.lastError();
}
bool DBManager::createPersonTable()
    {
    // Create table "person"
    bool ret = false;
    if (db.isOpen())
        {
        QSqlQuery query;
        ret = query.exec("create table person "
                  "(id integer primary key, "
                  "firstname varchar(20), "
                  "lastname varchar(30), "
                  "age integer)");

        }
    return ret;
    }

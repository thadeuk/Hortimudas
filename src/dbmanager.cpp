#include "dbmanager.h"

bool DBManager::openDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dbsqlite");
    return db.open();
}

QSqlError DBManager::lastError()
{
    return db.lastError();
}

DBManager::~DBManager()
{
    db.close();
}

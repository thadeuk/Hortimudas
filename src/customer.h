#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>
#include <QTableView>
#include <QSqlTableModel>

namespace Ui {
class Customer;
}

class Customer : public QDialog
{
    Q_OBJECT

public:
    explicit Customer(QWidget *parent = 0);
    ~Customer();
private:
    void CreateModel();
    Ui::Customer *ui;
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
    void CreateTable();
    void MapFields();
};

#endif // CUSTOMER_H

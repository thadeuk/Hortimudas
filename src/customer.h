#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>
#include <QTableView>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QSortFilterProxyModel>

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
    Ui::Customer *ui;
    QTableView *tableView;
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
    QSortFilterProxyModel *proxyModel;
    void CreateModel();
    void CreateTable();
    void MapFields();
    void CreateSignals();

public slots:
    void selectedRow(const QItemSelection &selected, const QItemSelection &deselect);
private slots:
    void on_addCustomer_clicked();
    void on_delCustomer_clicked();
    void on_filter_textChanged(const QString &str);
};

#endif // CUSTOMER_H

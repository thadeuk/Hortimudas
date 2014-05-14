#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <QDialog>
#include <QTableView>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QSortFilterProxyModel>

namespace Ui {
class Supplier;
}

class Supplier : public QDialog
{
    Q_OBJECT

public:
    explicit Supplier(QWidget *parent = 0);
    ~Supplier();
private:
    Ui::Supplier *ui;
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
    void on_addSupplier_clicked();
    void on_delSupplier_clicked();
    void on_filter_textChanged(const QString &str);
};

#endif // SUPPLIER_H

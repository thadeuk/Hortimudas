#ifndef LISTAFORNECEDORES_H
#define LISTAFORNECEDORES_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QItemSelectionModel>
namespace Ui {
class ListaFornecedores;
}

class ListaFornecedores : public QDialog
{
    Q_OBJECT
    QSqlTableModel *model;
    QSortFilterProxyModel *proxyModel;
public:
    explicit ListaFornecedores(QWidget *parent = 0);
    QItemSelectionModel* retornaSelectionModel();
    ~ListaFornecedores();
    
private:
    Ui::ListaFornecedores *ui;
public slots:
    void filtro();
};

#endif // LISTAFORNECEDORES_H

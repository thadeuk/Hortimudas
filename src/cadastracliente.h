#ifndef CADASTRACLIENTE_H
#define CADASTRACLIENTE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QSortFilterProxyModel>
#include <QItemSelection>
#include <QMessageBox>
#include <QSqlError>
#include <cadastracliente2.h>
namespace Ui {
class CadastraCliente;
}

class CadastraCliente : public QDialog
{
    Q_OBJECT
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
    QSortFilterProxyModel *proxyModel;
    CadastraCliente2 *cadastra;

public:
    explicit CadastraCliente(QWidget *parent = 0);
    ~CadastraCliente();
    
private:
    Ui::CadastraCliente *ui;
    void submitSemFechar();

public slots:
    void submit();
    void filtro();
    void novoCliente();
    void selectedRow(const QItemSelection &, const QItemSelection &);
    void removeCliente();
    void atualiza();
};

#endif // CADASTRACLIENTE_H

#ifndef CADASTRACONTASPAGAR_H
#define CADASTRACONTASPAGAR_H

#include <QDialog>
#include <pagar/listafornecedores.h>
#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QDataWidgetMapper>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
namespace Ui {
class CadastraContasPagar;
}

class CadastraContasPagar : public QDialog
{
    Q_OBJECT
    ListaFornecedores *fornecedores;
   // QSqlRelationalTableModel *model;
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;

public:
    explicit CadastraContasPagar(QWidget *parent = 0);
    ~CadastraContasPagar();
    
private:
    Ui::CadastraContasPagar *ui;

public slots:
    void showFornecedores();
    void selectionChangedSlot(const QItemSelection & /*newSelection*/, const QItemSelection & /*oldSelection*/);
    void submit();
};

#endif // CADASTRACONTASPAGAR_H

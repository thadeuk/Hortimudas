#ifndef CADASTRAFORNECEDOR_H
#define CADASTRAFORNECEDOR_H

#include <QDialog>
#include <QSqlTableModel>
#include <QtWidgets>
#include <QSqlError>
#include <QDataWidgetMapper>
#include <QSqlRecord>
#include <QSortFilterProxyModel>
#include <cadastrafornecedor2.h>

namespace Ui {
class CadastraFornecedor;
}

class CadastraFornecedor : public QDialog
{
    Q_OBJECT
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
    QSortFilterProxyModel *proxyModel;
    CadastraFornecedor2 *cadastra;
public:
    explicit CadastraFornecedor(QWidget *parent = 0);
    ~CadastraFornecedor();
    
private:
    Ui::CadastraFornecedor *ui;
    void submitSemFechar();

public slots:
        void submit();
        void filtro();
        void novoFornecedor();
        void selectedRow(const QItemSelection &, const QItemSelection &);
        void removeFornecedor();
        void atualiza();
};

#endif // CADASTRAFORNECEDOR_H

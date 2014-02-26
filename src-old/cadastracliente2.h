#ifndef CADASTRACLIENTE2_H
#define CADASTRACLIENTE2_H

#include <QDialog>
#include <QtWidgets>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlError>
namespace Ui {
class CadastraCliente2;
}

class CadastraCliente2 : public QDialog
{
    Q_OBJECT
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
public:
    explicit CadastraCliente2(QWidget *parent);
    ~CadastraCliente2();
    
private:
    Ui::CadastraCliente2 *ui;

public slots:
    void submit();
    void cancela();
};

#endif // CADASTRACLIENTE2_H

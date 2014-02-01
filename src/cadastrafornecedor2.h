#ifndef CADASTRAFORNECEDOR2_H
#define CADASTRAFORNECEDOR2_H

#include <QDialog>
#include <QtWidgets>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlError>
namespace Ui {
class CadastraFornecedor2;
}

class CadastraFornecedor2 : public QDialog
{
    Q_OBJECT
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
public:
    explicit CadastraFornecedor2(QWidget *parent);
    ~CadastraFornecedor2();
    
private:
    Ui::CadastraFornecedor2 *ui;

public slots:
    void submit();
    void cancela();
};

#endif // CADASTRAFORNECEDOR2_H

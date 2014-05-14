#include "accounts_payable.h"
#include "ui_accounts_payable.h"
#include <QSqlError>
#include <QDebug>
AccountsPayable::AccountsPayable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountsPayable)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setTable("fornecedores");
    model->select();
    completer = new QCompleter(this);
    completer->setModel(model);
    completer->setCompletionColumn(1);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->supplier->setCompleter(completer);

}

AccountsPayable::~AccountsPayable()
{
    this->parentWidget()->close();
    delete ui;
}

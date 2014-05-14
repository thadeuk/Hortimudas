#include "accounts_receivable.h"
#include "ui_accounts_receivable.h"

AccountsReceivable::AccountsReceivable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountsReceivable)
{
    ui->setupUi(this);
}

AccountsReceivable::~AccountsReceivable()
{
    delete ui;
}

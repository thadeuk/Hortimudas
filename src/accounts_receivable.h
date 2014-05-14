#ifndef ACCOUNTS_RECEIVABLE_H
#define ACCOUNTS_RECEIVABLE_H

#include <QDialog>

namespace Ui {
class AccountsReceivable;
}

class AccountsReceivable : public QDialog
{
    Q_OBJECT

public:
    explicit AccountsReceivable(QWidget *parent = 0);
    ~AccountsReceivable();

private:
    Ui::AccountsReceivable *ui;
};

#endif // ACCOUNTS_RECEIVABLE_H

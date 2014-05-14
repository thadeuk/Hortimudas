#ifndef ACCOUNTSPAYABLE_H
#define ACCOUNTSPAYABLE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QCompleter>

namespace Ui {
class AccountsPayable;
}

class AccountsPayable : public QDialog
{
    Q_OBJECT

public:
    explicit AccountsPayable(QWidget *parent = 0);
    ~AccountsPayable();

private:
    Ui::AccountsPayable *ui;
    QSqlTableModel *model;
    QCompleter *completer;
};

#endif // ACCOUNTSPAYABLE_H

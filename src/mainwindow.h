#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <customer.h>
#include <supplier.h>
#include <accounts_payable.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionFornecedores_triggered();

    void on_actionCliente_triggered();

    void on_actionContas_a_Receber_triggered();

    void on_actionContas_a_Pagar_triggered();

private:
    Ui::MainWindow *ui;
    QMdiArea *workspace;
    Customer *customer;
    Supplier *supplier;
    AccountsPayable *accountsPayable;
};

#endif // MAINWINDOW_H

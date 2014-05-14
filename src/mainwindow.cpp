#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customer.h"
#include <QMessageBox>
#include <QBoxLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    workspace = new QMdiArea;
    setCentralWidget(workspace);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionFornecedores_triggered()
{
    supplier = new Supplier(this);
    workspace->addSubWindow(supplier);
    supplier->show();
}

void MainWindow::on_actionCliente_triggered()
{
    customer = new Customer(this);
    workspace->addSubWindow(customer);
    customer->show();

}

void MainWindow::on_actionContas_a_Receber_triggered()
{

}

void MainWindow::on_actionContas_a_Pagar_triggered()
{
    accountsPayable = new AccountsPayable(this);
    workspace->addSubWindow(accountsPayable);
    accountsPayable->show();
}

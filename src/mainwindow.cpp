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

void MainWindow::onCustomerWindow()
{
    customer = new Customer(this);
    workspace->addSubWindow(customer);
    customer->show();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    workspace = new QMdiArea();
   setCentralWidget(workspace);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openCadastraCliente(){
    cadastraCliente = new CadastraCliente(this);
    cadastraCliente->setAttribute(Qt::WA_DeleteOnClose, true);
    workspace->addSubWindow(cadastraCliente);
    cadastraCliente->show();
}

void MainWindow::openCadastraFornecedor(){
    cadastraFornecedor = new CadastraFornecedor(this);
    cadastraFornecedor->setAttribute(Qt::WA_DeleteOnClose, true);
   // workspace->addSubWindow(cadastraFornecedor);
    cadastraFornecedor->show();
}

void MainWindow::openContasPagar(){
    cadastraContasaPagar = new CadastraContasPagar(this);
    //cadastraContasaPagar->setAttribute(Qt::WA_DeleteOnClose, true);
    //workspace->addSubWindow(cadastraContasaPagar);
    cadastraContasaPagar->show();
}

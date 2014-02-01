#include "listafornecedores.h"
#include "ui_listafornecedores.h"

ListaFornecedores::ListaFornecedores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaFornecedores)
{
    ui->setupUi(this);
}

ListaFornecedores::~ListaFornecedores()
{
    delete ui;
}

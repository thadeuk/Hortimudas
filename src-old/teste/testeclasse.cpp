#include "teste/testeclasse.h"
#include "ui_testeclasse.h"

testeClasse::testeClasse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testeClasse)
{
    ui->setupUi(this);
}

testeClasse::~testeClasse()
{
    delete ui;
}

#include "customer.h"
#include "ui_customer.h"

Customer::Customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Customer)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    CreateModel();

    CreateTable();
    MapFields();
}

void Customer::CreateModel()
{
    model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setTable("fornecedores");
    model->select();
}

void Customer::CreateTable()
{
    QTableView *table = ui->tableView;

    table->setModel(model);
   // table->horizontalHeader()->moveSection(1, 0);
   // table->sortByColumn(1, Qt::AscendingOrder);
    for (int i = 0; i < 11; i++) {
        if (i != 1)
            table->hideColumn(i);
    }
    table->horizontalHeader()->setStretchLastSection(true);
   // ui->tableView->selectRow(0);
}

void Customer::MapFields()
{
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(proxyModel);
    mapper->addMapping(ui->nome, model->fieldIndex("nome"));
    mapper->addMapping(ui->cpf, model->fieldIndex("cpf"));
    mapper->addMapping(ui->data, model->fieldIndex("datanascimento"));
    mapper->addMapping(ui->endereco, model->fieldIndex("endereco"));
    mapper->addMapping(ui->cidade, model->fieldIndex("cidade"));
    mapper->addMapping(ui->celular, model->fieldIndex("celular"));
    mapper->addMapping(ui->estado, model->fieldIndex("estado"));
    mapper->addMapping(ui->fixo, model->fieldIndex("telfixo"));
    mapper->addMapping(ui->data, model->fieldIndex("datanascimento"));
    mapper->addMapping(ui->rg   , model->fieldIndex("rg"));
}

Customer::~Customer()
{
    delete ui;
}

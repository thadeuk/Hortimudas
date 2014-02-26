#include "cadastrafornecedor2.h"
#include "ui_cadastrafornecedor2.h"

CadastraFornecedor2::CadastraFornecedor2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastraFornecedor2)
{
    ui->setupUi(this);
    model = new QSqlTableModel();
    model->setTable("fornecedores");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    mapper = new QDataWidgetMapper(this);
    QSqlRecord record = model->record();
    model->insertRecord(-1, record);
    mapper->setModel(model);
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
    mapper->toLast();
}

CadastraFornecedor2::~CadastraFornecedor2()
{
    delete ui;
}

void CadastraFornecedor2::submit()
{
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
        this->close();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cadastra Fornecedor"), tr("The database reported an error: %1").arg(model->lastError().text()));
    }
}

void CadastraFornecedor2::cancela()
{
    model->removeRow(model->rowCount()-1);
    this->close();
}

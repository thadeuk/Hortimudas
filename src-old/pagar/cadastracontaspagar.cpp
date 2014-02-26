#include "pagar/cadastracontaspagar.h"
#include "ui_cadastracontaspagar.h"

CadastraContasPagar::CadastraContasPagar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastraContasPagar)
{
    ui->setupUi(this);

 //   model = new QSqlRelationalTableModel(this);
 //   model->setTable("contaspagar");
 //   model->setEditStrategy(QSqlTableModel::OnManualSubmit);
 //   model->setRelation(5, QSqlRelation("fornecedores","id", "nome"));
 //   model->select();
    model = new QSqlTableModel(this);
    model->setTable("contaspagar");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

 //   model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    QSqlRecord record = model->record();
    model->insertRecord(-1, record);
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->addMapping(ui->descricao, model->fieldIndex("descricao"));
    mapper->addMapping(ui->dataconta, model->fieldIndex("dataconta"));
    mapper->addMapping(ui->vencimento, model->fieldIndex("vencimento"));
    mapper->addMapping(ui->contacaixa, model->fieldIndex("contacaixa"));
    mapper->addMapping(ui->valor, model->fieldIndex("valor"));
    mapper->addMapping(ui->observacao, model->fieldIndex("observacao"));
    mapper->toLast();

}

CadastraContasPagar::~CadastraContasPagar()
{
    delete ui;
}

void CadastraContasPagar::showFornecedores()
{
    fornecedores = new ListaFornecedores(this);
    connect(fornecedores->retornaSelectionModel(), SIGNAL(selectionChanged (const QItemSelection &, const QItemSelection &)),
                 this, SLOT(selectionChangedSlot(const QItemSelection &, const QItemSelection &)));
    fornecedores->show();
}

void CadastraContasPagar::selectionChangedSlot(const QItemSelection & /*newSelection*/, const QItemSelection & /*oldSelection*/)
{
    QModelIndex index = fornecedores->retornaSelectionModel()->currentIndex();
    QModelIndex index2 = fornecedores->retornaSelectionModel()->model()->index(index.row(),0);
    //this->ui->fornecedor->setText(index2.data().toString());
    this->ui->fornecedor->setText(index.data().toString());
    model->setData(model->index(model->rowCount()-1, 5), index2.data().toString());

}

void CadastraContasPagar::submit()
{
    mapper->submit();
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
        this->close();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Contas a Pagar"), tr("The database reported an error: %1").arg(model->lastError().text()));
    }
}


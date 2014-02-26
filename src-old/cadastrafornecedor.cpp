#include "cadastrafornecedor.h"
#include "ui_cadastrafornecedor.h"

CadastraFornecedor::CadastraFornecedor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastraFornecedor)
{
    ui->setupUi(this);
    model = new QSqlTableModel();
    model->setTable("fornecedores");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(1, Qt::Horizontal, tr("Nome"));
    model->setHeaderData(7, Qt::Horizontal, tr("Endereço"));
    model->setHeaderData(9, Qt::Horizontal, tr("Celular"));
    model->setHeaderData(10, Qt::Horizontal, tr("Tel. Residencial"));

    proxyModel = new QSortFilterProxyModel;
    proxyModel->setDynamicSortFilter(true);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setSourceModel(model);
    proxyModel->setFilterKeyColumn(1);


    ui->tableView->setModel(proxyModel);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->moveSection(1, 0);
    ui->tableView->sortByColumn(1, Qt::AscendingOrder);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(2);
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->hideColumn(8);
    ui->tableView->hideColumn(9);
    ui->tableView->hideColumn(10);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->selectRow(0);
    ui->tableView->show();

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
    mapper->toFirst();

    connect(
      ui->tableView->selectionModel(),
      SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
      SLOT(selectedRow(const QItemSelection &, const QItemSelection &))
     );
}

CadastraFornecedor::~CadastraFornecedor()
{
    delete ui;

}

void CadastraFornecedor::submit()
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

void CadastraFornecedor::submitSemFechar()
{
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cadastra Fornecedor"), tr("The database reported an error: %1").arg(model->lastError().text()));
    }
}

void CadastraFornecedor::filtro()
{
    proxyModel->setFilterRegExp(ui->filtro->text());
}

void CadastraFornecedor::novoFornecedor(){
    cadastra = new CadastraFornecedor2(this);
    connect(cadastra, SIGNAL(accepted()), this, SLOT(atualiza()));
    cadastra->exec();
}

void CadastraFornecedor::removeFornecedor(){

    QMessageBox msgBox;
    msgBox.setText("Tem certeza que deseja remover ?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setWindowTitle("Confirmação");
    int ret = msgBox.exec();
    if (ret == QMessageBox::Ok) {
        proxyModel->removeRow(mapper->currentIndex());
        this->submitSemFechar();
        model->select();
        mapper->toFirst();
    }
}
void CadastraFornecedor::selectedRow(const QItemSelection &selected, const QItemSelection &deselect)
{
    mapper->setCurrentIndex(ui->tableView->currentIndex().row());
}

void CadastraFornecedor::atualiza()
{
    model->select();
}

#include "pagar/listafornecedores.h"
#include "ui_listafornecedores.h"

ListaFornecedores::ListaFornecedores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaFornecedores)
{
    ui->setupUi(this);

    model = new QSqlTableModel();
    model->setTable("fornecedores");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
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

}

ListaFornecedores::~ListaFornecedores()
{
    delete ui;
}

void ListaFornecedores::filtro()
{
   proxyModel->setFilterRegExp(ui->filtro->text());
}

QItemSelectionModel* ListaFornecedores::retornaSelectionModel()
{
    return ui->tableView->selectionModel();
}

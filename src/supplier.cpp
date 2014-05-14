#include "supplier.h"
#include "ui_supplier.h"
#include <QSqlRecord>
#include <QDebug>

Supplier::Supplier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Supplier)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    CreateModel();
    CreateTable();
    MapFields();
    CreateSignals();

}

void Supplier::CreateModel()
{
    model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setTable("fornecedores");
    model->select();
    model->setHeaderData(1, Qt::Horizontal, tr("Nome"));

    proxyModel = new QSortFilterProxyModel;
    proxyModel->setDynamicSortFilter(true);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setSourceModel(model);
    proxyModel->setFilterKeyColumn(1);
}

void Supplier::CreateTable()
{
    tableView = ui->tableView;

    tableView->setModel(proxyModel);
    tableView->verticalHeader()->setVisible(false);
    tableView->sortByColumn(1, Qt::AscendingOrder);
    for (int i = 0; i < 11; i++)
        tableView->hideColumn(i);
    tableView->showColumn(1);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->selectRow(0);
}

void Supplier::MapFields()
{
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    mapper->setModel(proxyModel);
    mapper->addMapping(ui->name, model->fieldIndex("nome"));
    mapper->addMapping(ui->cpf, model->fieldIndex("cpf"));
    mapper->addMapping(ui->rg   , model->fieldIndex("rg"));
    mapper->addMapping(ui->birthday, model->fieldIndex("datanascimento"));
    mapper->addMapping(ui->address, model->fieldIndex("endereco"));
    mapper->addMapping(ui->city, model->fieldIndex("cidade"));
    mapper->addMapping(ui->mobilePhoneNumber, model->fieldIndex("celular"));
    mapper->addMapping(ui->state, model->fieldIndex("estado"));
    mapper->addMapping(ui->phoneNumber, model->fieldIndex("telfixo"));

    mapper->setCurrentIndex(ui->tableView->currentIndex().row());
}

void Supplier::CreateSignals()
{
    connect(
      tableView->selectionModel(),
      SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
      SLOT(selectedRow(const QItemSelection &, const QItemSelection &))
     );
}

void Supplier::selectedRow(const QItemSelection &selected, const QItemSelection &deselect)
{
    if (!selected.indexes().empty())
        mapper->setCurrentModelIndex(selected.indexes().first());
}


Supplier::~Supplier()
{
    this->parentWidget()->close();
    delete ui;
}

void Supplier::on_addSupplier_clicked()
{
    QSqlRecord rec( model->record() );
    model->insertRecord(-1, rec );
    model->select();
    tableView->sortByColumn(1, Qt::AscendingOrder);
    tableView->selectRow(0);
}

void Supplier::on_delSupplier_clicked()
{
    int row = tableView->currentIndex().row();
    proxyModel->removeRow(row);
    model->select();
}

void Supplier::on_filter_textChanged(const QString &str)
{
    proxyModel->setFilterRegExp(str);
}


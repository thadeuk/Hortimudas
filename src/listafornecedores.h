#ifndef LISTAFORNECEDORES_H
#define LISTAFORNECEDORES_H

#include <QDialog>

namespace Ui {
class ListaFornecedores;
}

class ListaFornecedores : public QDialog
{
    Q_OBJECT
    
public:
    explicit ListaFornecedores(QWidget *parent = 0);
    ~ListaFornecedores();
    
private:
    Ui::ListaFornecedores *ui;
};

#endif // LISTAFORNECEDORES_H

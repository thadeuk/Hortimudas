#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMdiArea>
#include <cadastracliente.h>
#include <cadastrafornecedor.h>
#include <pagar/cadastracontaspagar.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    CadastraCliente *cadastraCliente;
    CadastraFornecedor *cadastraFornecedor;
    CadastraContasPagar *cadastraContasaPagar;
    QMdiArea *workspace;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

public slots:
    void openCadastraCliente();
    void openCadastraFornecedor();
    void openContasPagar();
};

#endif // MAINWINDOW_H

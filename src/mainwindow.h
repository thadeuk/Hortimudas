#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <customer.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onCustomerWindow();

private:
    Ui::MainWindow *ui;
    QMdiArea *workspace;
    Customer *customer;
};

#endif // MAINWINDOW_H

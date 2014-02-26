#ifndef TESTECLASSE_H
#define TESTECLASSE_H

#include <QDialog>

namespace Ui {
class testeClasse;
}

class testeClasse : public QDialog
{
    Q_OBJECT
    
public:
    explicit testeClasse(QWidget *parent = 0);
    ~testeClasse();
    
private:
    Ui::testeClasse *ui;
};

#endif // TESTECLASSE_H

#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include "cmdvente.h"
namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();
     void paintEvent(QPaintEvent *);

private:
    Ui::statistique *ui;
    cmdvente e ;
};

#endif // STATISTIQUE_H

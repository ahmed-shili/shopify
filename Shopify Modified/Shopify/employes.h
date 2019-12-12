#ifndef EMPLOYES_H
#define EMPLOYES_H

#include <QMainWindow>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QApplication>
#include <QMessageBox>
#include "conges.h"
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QDateTime>
#include "popup.h"
namespace Ui {
class employes;
}

class employes : public QMainWindow
{
    Q_OBJECT

public:
    explicit employes(QWidget *parent = nullptr);
    ~employes();

private slots:
    void sendMail();
    void mailSent(QString);
    void on_AjouterCTW_clicked();

    void on_IDAfficherC_textChanged(const QString &arg1);

    void on_SupprimerCTW_clicked();

    void on_tv_gestionC_activated(const QModelIndex &index);

    void on_ModiferCTW_clicked();

private:
    Ui::employes *ui;
    conges c;
    PopUp *popUp;
};

#endif // EMPLOYES_H

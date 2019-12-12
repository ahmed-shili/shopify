#include "employes.h"
#include "ui_employes.h"

employes::employes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::employes)
{
    ui->setupUi(this);
    popUp = new PopUp();
    ui->tv_gestionC->setModel(c.afficher());
    connect(ui->sendbtc, SIGNAL(clicked()),this, SLOT(sendMail()));
    QRegExp rx("[A-Za-z_]+");//[A-Za-z0-9_]
        QRegExp rx1("[0-9_]+");
        QValidator *validator = new QRegExpValidator(rx, this);
        QValidator *validator2 = new QRegExpValidator(rx1, this);
    ui->le_nomc->setValidator(validator);
    ui->le_prenomc->setValidator(validator);
    ui->le_typec->setValidator(validator);
    ui->le_idc->setValidator(validator2);

}

employes::~employes()
{
    delete ui;
}

void employes::on_AjouterCTW_clicked()
{
    int id = ui->le_idc->text().toInt();
    QString nom= ui->le_nomc->text();
    QString prenom= ui->le_prenomc->text();
    QString type= ui->le_typec->text();
    QDateTime debut = ui->dt_de->dateTime();
    QDateTime fin= ui->dt_ju->dateTime();
    int etat=0;
     conges e(id, nom, prenom,type, debut,fin,etat);
  bool test=e.ajouter();
  if(test)
{
      ui->tv_gestionC->setModel(c.afficher());//refresh
popUp->setPopupText("Conges ajouté");
  popUp->show();
}
  else
  {popUp->setPopupText("Erreur !");
  popUp->show();}
}

void employes::on_IDAfficherC_textChanged(const QString &arg1)
{
    ui->tv_gestionC->setModel(c.recherche(arg1));
}

void employes::on_SupprimerCTW_clicked()
{
    int id = ui->IDAfficherC->text().toInt();
    bool test=c.supprimer(id);
    if(test)
    {ui->tv_gestionC->setModel(c.afficher());//refresh
        popUp->setPopupText("Conges supprimé");
            popUp->show();

    }
    else
    {popUp->setPopupText("Erreur !");
    popUp->show();}
}

void employes::sendMail()
{
    Smtp *smtp= new Smtp(ui->le_mailc->text(), ui->le_passcc->text(),"smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->le_mailc->text(),"motaz.mezrani@esprit.tn" , ui->le_subc->text(),ui->txtemailc->toPlainText());
}

void employes::mailSent(QString status)
{
    if(status == "Message sent")
    {
        popUp->setPopupText("Message sent!");
        popUp->show();
    }
}



void employes::on_tv_gestionC_activated(const QModelIndex &index)
{
    QString val=ui->tv_gestionC->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from conges where idc='"+val+"'");
    if (qry.exec( ))
    {
                  while(qry.next())
                    {
                        ui->le_idc->setText(qry.value(0).toString());
                        ui->le_nomc->setText(qry.value(1).toString());
                        ui->le_prenomc->setText(qry.value(2).toString());
                        ui->le_typec->setText(qry.value(3).toString());
                        ui->dt_de->setDateTime(qry.value(4).toDateTime());
                        ui->dt_ju->setDateTime(qry.value(5).toDateTime());

                    }
                }
}

void employes::on_ModiferCTW_clicked()
{
    int id = ui->le_idc->text().toInt();
    QString nom= ui->le_nomc->text();
    QString prenom= ui->le_prenomc->text();
    QString type= ui->le_typec->text();
    QDateTime debut = ui->dt_de->dateTime();
    QDateTime fin= ui->dt_ju->dateTime();
    int etat;
     conges e(id, nom, prenom,type, debut,fin,etat);

  bool test=e.modifier();
  if(test)
ui->tv_gestionC->setModel(c.afficher());
}

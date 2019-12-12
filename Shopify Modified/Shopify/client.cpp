#include "client.h"
#include<QMessageBox>
client::client()
{ nom ="";
    prenom ="";
    adresse="";
    cin=0;

}
client ::client(int cin,QString nom,QString prenom,QString adresse){

    this->nom=nom;
    this->prenom=prenom;
   this->adresse=adresse;
this->cin=cin;
}
QString client ::getnom(){
    return nom;}

QString client ::getprenom(){
    return prenom;}
QString client ::getadresse(){
    return adresse;}

int client ::getcin(){
    return cin;}

void client::setcin(int cin){
    this->cin=cin;
}
void client::setnom(QString nom){
    this->nom=nom;
}
void client::setprenom(QString prenom){
    this->prenom=prenom;
}
void client ::setadresse(QString adresse){
    this->adresse=adresse;
}

bool client ::ajouter(){

  QSqlQuery query; // naamlou biha lec commande taa ajout ou supp wala

  //QString res= QString::number(CIN);
  query.prepare("INSERT INTO CLIENT_CRUD (PRENOM,NOM,CIN,ADRESSE)"
                "VALUES (:PRENOM, :NOM, :CIN, :ADRESSE)");
 query.bindValue(":PRENOM", prenom); // nsaker l valeur mte3i b hedehka
  query.bindValue(":NOM", nom);
  query.bindValue(":CIN", cin);
  query.bindValue(":ADRESSE", adresse);


  return    query.exec();
}


QSqlQueryModel *client::afficher(QString r)
{
    QSqlQueryModel *model=new QSqlQueryModel(); // model taa affichage
    model->setQuery(r);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    return  model;


}
bool client::supprimer(int cin){

    QSqlQuery query;
    query.prepare("Delete from CLIENT_CRUD where CIN= :CIN");
    query.bindValue(":CIN", cin);
    return query.exec();


}

QSqlQueryModel * client::triecin()
{
    QSqlQueryModel * model= new QSqlQueryModel(); // model taameli retour

    model->setQuery("select * from CLIENT_CRUD order by CIN");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));


    return model;
}

bool client::modifier()
{
    QSqlQuery query;

    query.prepare("Update CLIENT_CRUD set NOM=:NOM ,PRENOM=:PRENOM,CIN=:CIN,ADRESSE=:ADRESSE where CIN=:CIN");
        query.bindValue(":PRENOM", getprenom());
    query.bindValue(":NOM", getnom());


    query.bindValue(":CIN", getcin());
    query.bindValue(":ADRESSE", getadresse());


    return query.exec();
}

client client ::getclient(int cin){
    QSqlQuery query;
        QString res= QString::number(cin);
        query.prepare("Select *from CLIENT_CRUD where CIN = :CIN ");
        query.bindValue(":CIN", res);
        query.exec() ;
        client eq;
        if(query.exec())
        {
            QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                        QObject::tr("client trouvé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

            while(query.next())
            {
                 eq.setnom(query.value(0).toString());
                 eq.setprenom(query.value(1).toString());
                 eq.setcin(query.value(2).toInt());
                 eq.setadresse(query.value(3).toString());

            }

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Rechercher un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }

        return  eq ;}
QSqlQueryModel *client::rechercher(QString nom){

    QSqlQuery query;
    query.prepare("select * from CLIENT_CRUD where NOM like '%"+nom+"%'");
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));


        return model;

}









#include "cmdachat.h"
#include<QSqlQuery>

#include <QDebug>
#include <QDate>
cmdachat::cmdachat()
{
id=0;
nom="";


}
cmdachat::cmdachat(int id,QString nom,int num_article,int quantite)
{
  this->id=id;
  this->nom=nom;

    this->num_article=num_article;
    this->quantite=quantite;


}
QString cmdachat::get_nom(){return  nom;}

int cmdachat::get_id(){return  id;}
int cmdachat::get_num(){return  num_article;}
int  cmdachat::get_quantite() {return quantite;}

bool cmdachat::ajouter()


{
QSqlQuery query;
QString res= QString::number(id);
QString re= QString::number(num_article);
QString r= QString::number(quantite);

query.prepare("INSERT INTO CMDACHAT(ID, NOM,NUM_ARTICLE,QUANTITE) "
                    "VALUES (:id, :nom,:num_article,:quantite)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);

query.bindValue(":num_article", re);
query.bindValue(":quantite", r);


return    query.exec();
}

QSqlQueryModel * cmdachat::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CMDACHAT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_article"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));


    return model;
}

bool cmdachat::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from CMDACHAT where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool cmdachat::modifier(int id , QString nom  ,int num_article,int quantite)
{
    QSqlQuery query;
QString res= QString::number(id);
QString re= QString::number(num_article);
QString r= QString::number(quantite);
    query.prepare("update CMDACHAT set ID=:id,NOM=:nom,NUM_ARTICLE=:num_article,QUANTITE=:quantite where ID=: id");
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":num_article", re);
    query.bindValue(":quantite", r);




    return query.exec();
}
QSqlQueryModel *cmdachat::rechercher1(QString id){

    QSqlQuery query;
    query.prepare("select * from CMDACHAT where ID like '%"+id+"%'");
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_article"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));


        return model;

}



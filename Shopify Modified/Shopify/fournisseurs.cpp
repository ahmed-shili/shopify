#include "fournisseurs.h"
#include <QDebug>

fournisseurs::fournisseurs()
{
    nom="";
    prenom="";
    id=0;
}
fournisseurs::fournisseurs (QString nom,QString prenom,int id)
{
  this->nom=nom;
  this->prenom=prenom;
  this->id=id;
}
QString fournisseurs::get_nom(){return  nom;}
QString fournisseurs::get_prenom(){return prenom;}
int fournisseurs::get_id(){return  id;}

bool fournisseurs::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO fournisseurs ( ID, NOM,PRENOM) "
                    "VALUES (:id, :nom, :prenom)");

query.bindValue(":id", id);
query.bindValue(":prenom", prenom);
query.bindValue(":nom", nom);

return    query.exec();
}

QSqlQueryModel * fournisseurs::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fournisseurs");
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;
}

QSqlQueryModel * fournisseurs::tri()
{
    QSqlQuery query;
    query.prepare("select * from fournisseurs order by id DESC");
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

        return model;
}
QSqlQueryModel * fournisseurs::rechercher(QString nom )
{


QSqlQuery query;
query.prepare("select * from fournisseurs where nom like '%"+nom+"%'");
query.exec();
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery(query);
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));


    return model;
}

bool fournisseurs::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from fournisseurs where ID = :id ");
query.bindValue(":id", id);
return    query.exec();

}
bool fournisseurs::modifierid(QString ide,int id)
{
    QSqlQuery query;
   // QString res= QString::number(nbnuit);
    query.prepare("UPDATE fournisseurs set id=:ide where id=:id ");
    query.bindValue(":ide", ide);
query.bindValue(":id", id);
    return    query.exec();

}


bool fournisseurs::modifiernom(QString nom,int id)
{
    QSqlQuery query;
   // QString res= QString::number(nbnuit);
    query.prepare("UPDATE fournisseurs set nom=:nom where id=:id ");
    query.bindValue(":nom", nom);
query.bindValue(":id", id);
    return    query.exec();

}
bool fournisseurs::modifierprenom(QString prenom,int id)
{
    QSqlQuery query;
   // QString res= QString::number(nbnuit);
    query.prepare("UPDATE stock set categorie=:cat where iden=:iden ");
    query.bindValue(":prenom", prenom);
query.bindValue(":id", id);
    return    query.exec();

}

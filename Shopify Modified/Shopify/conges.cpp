#include "conges.h"
#include <QDebug>
conges::conges()
{
id=0;
nom="";
prenom="";
type="";
}
conges::conges(int id, QString nom, QString prenom, QString type, QDateTime debut, QDateTime fin, int etat)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
    this->type=type;
    this->debut=debut;
    this->fin=fin;
    this->etat=etat;

}
QString conges::get_nom(){return  nom;}
QString conges::get_prenom(){return prenom;}
int conges::get_id(){return  id;}
QString conges::get_type(){return type;}
QDateTime conges::get_debut(){return debut;}
QDateTime conges::get_fin(){return fin;}


bool conges::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO CONGES (IDC, NOM, PRENOM,TYPE,DEBUT,FIN) "
                    "VALUES (:IDC, :NOM, :PRENOM, :TYPE, :DEBUT, :FIN)");
query.bindValue(":IDC", id);
query.bindValue(":NOM", nom);
query.bindValue(":PRENOM", prenom);
query.bindValue(":TYPE", type);
query.bindValue(":DEBUT", debut);
query.bindValue(":FIN", fin);
return    query.exec();
}

QSqlQueryModel * conges::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select *from CONGES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDC"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DEBUT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("FIN"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}

bool conges::supprimer(int id)
{
QSqlQuery query;
query.prepare("Delete from CONGES where IDC = :IDC ");
query.bindValue(":IDC", id);
return    query.exec();
}
bool conges::modifier()
{
QSqlQuery query;

query.prepare("update  CONGES set  NOM = :NOM , PRENOM = :PRENOM , TYPE = :TYPE, DEBUT= :DEBUT, FIN= :FIN,   where IDC = :IDC ");
query.bindValue(":IDC", id);
query.bindValue(":NOM", nom);
query.bindValue(":PRENOM", prenom);
query.bindValue(":TYPE", type);
query.bindValue(":DEBUT", debut);
query.bindValue(":FIN", fin);

return    query.exec();
}
bool conges::modifierconges()
{
    QSqlQuery query;
    query.prepare("update  CONGES set  ETAT = :ETAT  where IDC = :IDC ");
    query.bindValue(":IDC", id);
    query.bindValue(":ETAT", etat);

    return    query.exec();


}
QSqlQueryModel * conges::recherche(QString valeur )
{
 QSqlQueryModel * model = new QSqlQueryModel() ;
 QSqlQuery query;
query.prepare("SELECT * FROM CONGES WHERE IDC like '%"+valeur+"%'");
 query.bindValue(":valeur",valeur);
 query.exec();
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDC"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("DEBUT"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("FIN"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));
 return  model;
}

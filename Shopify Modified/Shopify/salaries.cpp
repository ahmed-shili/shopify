#include "salaries.h"
#include <QDebug>
salaries::salaries()
{
id=0;
nom="";
prenom="";
email="";
post="";
}
salaries::salaries(int id,QString nom,QString prenom,QString email,QString post,int etat)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
    this->email=email;
    this->post=post;
        this->etat=etat;
}
QString salaries::get_nom(){return  nom;}
QString salaries::get_prenom(){return prenom;}
int salaries::get_id(){return  id;}
QString salaries::get_email(){return email;}
QString salaries::get_post(){return post;}
int salaries::get_etat(){return  etat;}

bool salaries::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO SALARIES (ID, NOM, PRENOM,EMAIL,POST) "
                    "VALUES (:ID, :NOM, :PRENOM, :EMAIL, :POST)");
query.bindValue(":ID", id);
query.bindValue(":NOM", nom);
query.bindValue(":POST", prenom);
query.bindValue(":EMAIL", email);
query.bindValue(":PRENOM", post);

return    query.exec();
}

QSqlQueryModel * salaries::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select *from SALARIES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("POST"));
    return model;
}

bool salaries::supprimer(int id)
{
QSqlQuery query;
query.prepare("Delete from SALARIES where id = :ID ");
query.bindValue(":ID", id);
return    query.exec();
}
QSqlQueryModel * salaries::recherche(QString valeur )
{
 QSqlQueryModel * model = new QSqlQueryModel() ;
 QSqlQuery query;
query.prepare("SELECT * FROM SALARIES WHERE ID like '%"+valeur+"%'");
 query.bindValue(":valeur",valeur);
 query.exec();
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("POST"));
 return  model;
}
bool salaries::modifier()
{
QSqlQuery query;

query.prepare("update  SALARIES set  NOM = :NOM , PRENOM = :PRENOM , EMAIL = :EMAIL, POST= :POST   where ID = :ID ");
query.bindValue(":ID", id);
query.bindValue(":NOM", nom);
query.bindValue(":POST", prenom);
query.bindValue(":EMAIL", email);
query.bindValue(":PRENOM", post);

return    query.exec();
}


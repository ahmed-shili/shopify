#include "evenement.h"
#include <QDebug>
#include "articles.h"


evenement::evenement()
{
typee="";
saison="";
}
evenement::evenement(QString typee,QString saison,QDateTime date_debut,QDateTime date_fin)

{
  this->typee=typee;
  this->saison=saison;
  this->date_debut=date_debut;
  this->date_fin=date_fin;
}

QString evenement::get_type(){return  typee;}
QString evenement::get_saison(){return  saison;}
QDateTime evenement::get_date_debut(){return date_debut;}
QDateTime evenement::get_date_fin(){return date_fin;}



bool evenement::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO tabevenements (typee,saison,date_debut,date_fin) "
              "VALUES (:typee , :saison, :date_debut, :date_fin)");

query.bindValue(":typee",typee);
query.bindValue(":saison",saison);
query.bindValue(":date_debut",date_debut);
query.bindValue(":date_fin",date_fin);

return    query.exec();
}


QSqlQueryModel * evenement::afficher(QString r)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT *FROM tabevenements "
);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("typee"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("saison "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_debut"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_fin"));
    return model;
}

bool evenement::supprimer(QString typee)
{
QSqlQuery query;
query.prepare("Delete from tabevenements where typee = :typee ");
query.bindValue(":typee", typee);
return    query.exec();
}

/*
QSqlQueryModel * evenement::afficherj(QString type)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery r;
r.prepare("SELECT * FROM tabevenements INNER JOIN tabarticles ON tabevenements.typee =:typee ");
r.bindValue(":typee",type);
r.exec();
//where typee='aaa'
model->setQuery(r);

return  model;
}  */
//(SELECT FROM tabevenements WHERE tabevenements.typee =:tabarticles.type)

// SELECT annonce.* FROM annonce
// INNER JOIN ( SELECT cedonttuasbesoin FROM critere WHERE contenu = 2 AND contenu = 6 ) ON annonce.id=a.annonce
// AND (tabevenements.typee =:tabarticles.type)
//SELECT *
//FROM A
//INNER JOIN B ON A.key = B.key

bool evenement::modifier(QString typee, QString saison, QDateTime date_debut, QDateTime date_fin)
{
    QSqlQuery query;
    query.prepare("Update tabevenements set TYPEE=:typee ,SAISON=:saison,DATE_DEBUT=:date_debut,DATE_FIN=:date_fin where TYPEE=:typee");
    query.bindValue(":typee", typee);
    query.bindValue(":saison", saison);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);

    return query.exec();
}

bool evenement::modifier2()
{
    QSqlQuery query;
    query.prepare("Update tabevenements set TYPEE=:typee ,SAISON=:saison,DATE_DEBUT=:date_debut,DATE_FIN=:date_fin where TYPEE=:typee");
    query.bindValue(":typee", typee);
    query.bindValue(":saison", saison);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);

return    query.exec();
}

QSqlQueryModel * evenement::affichertypee (QString typee)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("select * from tabevenements where TYPEE like  '%"+typee+"%'")  ;
    query.bindValue(":typee",typee);
query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("typee"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("saison "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_debut"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_fin"));

return model;
}

QSqlQueryModel * evenement::afficherj(QString type)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery r;
 r.prepare("SELECT * FROM tabevenements INNER JOIN tabarticles ON tabevenements.typee =:typee AND tabarticles.type =:typee");
r.bindValue(":typee",type);
r.exec();
//where typee='aaa'
model->setQuery(r);
return  model;
}

QSqlQueryModel * evenement::afficheraffecter(QString type)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery r,m;
    r.prepare("SELECT typee,saison,date_debut,date_fin,date_expiration,numero,quantites FROM tabevenements JOIN tabarticles ON tabevenements.typee =:typee AND tabarticles.type =:typee");
  //  r.prepare("SELECT typee,saison,date_debut,date_fin FROM tabevenements");
   // r.prepare("alter Table tabevenements add(C6 number(6,3)null ,C7 varchar2(30) default('Tunis')null");
    r.bindValue(":typee",type);
    r.exec();
    model->setQuery(r);
    return  model;

}

QSqlQueryModel *evenement::afficherTriE(QString triE)
{
    QSqlQueryModel *m=new QSqlQueryModel();
    m->setQuery("select * from tabevenements order by "+triE);
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("typee"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("saison"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("date_debut"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("date_fin"));
    return m;
}

#include "articles.h"
#include <QDebug>
#include<QMessageBox>

articles::articles()
{
type="";
numero=0;
quantites=0;
}


articles::articles(int numero ,QString type,int quantites,QDateTime date_expiration)
{
  this->type=type;
  this->numero=numero;
  this->quantites=quantites;
  this->date_expiration=date_expiration;
}
QString articles::get_type(){return  type;}
QDateTime articles::get_date_expiration(){return date_expiration;}
int articles::get_numero(){return  numero;}
int articles::get_quantites(){return quantites;}

void articles::setnumero(int numero){
    this->numero=numero;
}
void articles::settype(QString type){
    this->type=type;
}
void articles::setquantites(int quantites){
    this->quantites=quantites;
}
void articles ::setdate(QDateTime date_expiration){
    this->date_expiration=date_expiration;
}

QSqlQueryModel * articles::afficherid (QString id)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("select * from tabarticles where NUMERO like '%"+id+"%'")  ;
    query.bindValue(":id",id);
query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantites"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_expiration"));

return model;
}
/*
QSqlQueryModel * fournisseurs::rechercher(QString nom)
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
*/
bool articles::ajouter()
{
QSqlQuery query;
//QString res= QString::number(id);
query.prepare("INSERT INTO tabarticles (numero,type,quantites,date_expiration) "
                    "VALUES (:numero, :type, :quantites, :date_expiration)");
query.bindValue(":numero", numero);
query.bindValue(":type", type);
query.bindValue(":quantites", quantites);
query.bindValue(":date_expiration", date_expiration);

return    query.exec();
}

QSqlQueryModel * articles::afficher(QString rech)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from tabarticles");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantites"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_expiration"));

    return model;
}

bool articles::supprimer(int numero)
{
QSqlQuery query;
QString res= QString::number(numero);
query.prepare("Delete from tabarticles where numero = :numero ");
query.bindValue(":numero", numero);
return    query.exec();
}


bool articles::modifier(int numero, QString type, int quantites, QDateTime date_expiration)
{
    QSqlQuery query;
    QString num=QString::number(numero);
    QString quan=QString::number(quantites);
    query.prepare("Update tabarticles set TYPE=:type ,QUANTITES=:quantites,DATE_EXPIRATION=:date_expiration where NUMERO=:numero");
    query.bindValue(":numero", num);
    query.bindValue(":quantites", quan);
    query.bindValue(":type", type);
    query.bindValue(":date_expiration", date_expiration);

    return query.exec();
}
bool articles::modifier2()
{
QSqlQuery query;

query.prepare("Update tabarticles set TYPE=:type ,QUANTITES=:quantites,DATE_EXPIRATION=:date_expiration where NUMERO=:numero");
query.bindValue(":numero", numero);
query.bindValue(":quantites", quantites);
query.bindValue(":type", type);
query.bindValue(":date_expiration", date_expiration);

return    query.exec();
}



QSqlQueryModel * articles::triequantites()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from tabarticles order by QUANTITES");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("NUMERO"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("QUANTITES"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_EXPIRATION"));


    return model;
}

QSqlQueryModel * articles::trienumero()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from tabarticles order by NUMERO");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("NUMERO"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("QUANTITES"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_EXPIRATION"));


    return model;
}

QSqlQueryModel *articles::afficherTriA(QString triA)
{
    QSqlQueryModel *m=new QSqlQueryModel();
    m->setQuery("select * from tabarticles order by "+triA);
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITES"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_EXPIRATION"));
    return m;
}

articles articles ::getarticle(int numero){
    QSqlQuery query;
        QString res= QString::number(numero);
        query.prepare("Select * from tabarticles where NUMERO = :NUMERO ");
        query.bindValue(":NUMERO", res);
        query.exec() ;
        articles eq;
        if(query.exec())
        {
            QMessageBox::information(nullptr, QObject::tr("modifier un articles"),
                        QObject::tr("articles trouvé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

            while(query.next())
            {
                 eq.settype(query.value(1).toString());
                 eq.setnumero(query.value(0).toInt());
                 eq.setquantites(query.value(2).toInt());
                 eq.setdate(query.value(3).toDateTime());

            }

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Rechercher un articles"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }

        return  eq ;}

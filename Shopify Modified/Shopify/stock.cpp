#include "stock.h"
#include <QDebug>

stock::stock()
{
    cat="";
    marque="";
    type="";
    iden=0;

}
stock::stock (int iden,QString cat,QString marque,QString type)
{
  this->cat=cat;
  this->marque=marque;
   this->type=type;
  this->iden=iden;
}
QString stock::get_cat(){return  cat;}
QString stock::get_type(){return type;}
int stock::get_iden(){return  iden;}
QString stock::get_marque(){return marque;}

bool stock::ajouters()
{
QSqlQuery query;

query.prepare("INSERT INTO stock ( IDEN, CATEGORIE,MARQUE,TYPE) "
                    "VALUES (:iden, :cat, :marque, :type)");

query.bindValue(":iden", iden);
query.bindValue(":cat", cat);
query.bindValue(":marque", marque);
query.bindValue(":type", type);
return    query.exec();
}

QSqlQueryModel * stock::affichers()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from stock");
model->setHeaderData(1, Qt::Horizontal, QObject::tr("cat"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("iden"));
    return model;
}

QSqlQueryModel * stock::tris()
{
    QSqlQuery query;
    query.prepare("select * from stock order by iden DESC");
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("iden"));
        return model;
}
QSqlQueryModel * stock::recherchers(QString cat)
{

QSqlQuery query;
query.prepare("select * from stock where categorie like '%"+cat+"%'");
query.exec();
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery(query);
model->setHeaderData(1, Qt::Horizontal, QObject::tr("cat"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("iden"));
    return model;
}

bool stock::supprimers(int iden)
{
QSqlQuery query;
QString res= QString::number(iden);
query.prepare("Delete from stock where iden = :iden ");
query.bindValue(":iden", iden);
return    query.exec();

}
bool stock::modifieriden(QString xiden,int iden)
{
    QSqlQuery query;

    query.prepare("UPDATE stock set iden = :xiden where iden = :iden");
    query.bindValue(":xiden", xiden);
   query.bindValue(":iden", iden);
;

    return    query.exec();

}

bool stock::modifiermarque(QString marque,int iden)
{
    QSqlQuery query;
   // QString res= QString::number(nbnuit);
    query.prepare("UPDATE stock set marque=:marque where iden=:iden ");
    query.bindValue(":marque", marque);
query.bindValue(":iden", iden);
    return    query.exec();

}


bool stock::modifiertype(QString type,int iden)
{
    QSqlQuery query;
   // QString res= QString::number(nbnuit);
    query.prepare("UPDATE stock set type=:type where iden=:iden ");
    query.bindValue(":type", type);
query.bindValue(":iden", iden);
    return    query.exec();

}
bool stock::modifiercategorie(QString cat,int iden)
{
    QSqlQuery query;
   // QString res= QString::number(nbnuit);
    query.prepare("UPDATE stock set categorie=:cat where iden=:iden ");
    query.bindValue(":cat", cat);
query.bindValue(":iden", iden);
    return    query.exec();

}

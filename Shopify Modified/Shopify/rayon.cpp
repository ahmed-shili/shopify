#include "rayon.h"

Rayon::Rayon(int a, QString b, int d, QString e)
{
    NumRayon=a;
    TypeProd=b;
    EtatRayon=d;
    ResRayon=e;
}

bool Rayon::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RAYON (NUMRAYON,TYPEPROD,ETATRAYON,RESRAYON) "
                        "VALUES (:NumRayon , :TypeProd , :EtatRayon , :RespRayon)");
    query.bindValue(":NumRayon",NumRayon);
    query.bindValue(":TypeProd",TypeProd);
    query.bindValue(":EtatRayon",EtatRayon);
    query.bindValue(":RespRayon",ResRayon);
    return query.exec();
}

QSqlQueryModel *Rayon::afficher()
{
    QSqlQueryModel *m=new QSqlQueryModel();
    m->setQuery("select * from Rayon");
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Rayon"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("Type Rayon"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat Rayon"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("Res. Rayon"));
    return m;
}

QSqlQueryModel *Rayon::rechercher(QString num)
{
    QSqlQuery query;
    QSqlQueryModel *m= new QSqlQueryModel();
    query.prepare("select * from rayon where NUMRAYON like '"+num+"%'");
    query.exec();
    m->setQuery(query);
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Rayon"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("Type Rayon"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat Rayon"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("Resp. Rayon"));
    return m;
}

bool Rayon::modifier(int a, QString b, int c, QString d, int num)
{
    QSqlQuery query;
    query.prepare("Update rayon set NUMRAYON=:NUMRAYON ,TYPEPROD=:TYPEPROD,ETATRAYON=:ETATRAYON, RESRAYON=:RESRAYON where NUMRAYON=:num");
    query.bindValue(":NUMRAYON",a);
    query.bindValue(":TYPEPROD",b);
    query.bindValue(":ETATRAYON",c);
    query.bindValue(":RESRAYON",d);
    query.bindValue(":num",num);
    return query.exec();
}

bool Rayon::supprimer(int num)
{    QSqlQuery query;
     query.prepare("Delete from rayon where NUMRAYON=:num");
     query.bindValue(":num",num);
     return query.exec();
}

QSqlQueryModel *Rayon::afficherTri(QString tri)
{
    QSqlQueryModel *m=new QSqlQueryModel();
    m->setQuery("select * from rayon order by "+tri);
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Rayon"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("Type Rayon"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat Rayon"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("Res. Rayon"));
    return m;
}

bool Rayon::affecterResR(int num, QString res)
{
    QSqlQuery query;
    query.prepare("Update RAYON set ETATRAYON=1,RESRAYON=:res where NUMCAISSE=:num");
    query.bindValue(":num",num);
    query.bindValue(":res",res);
    return query.exec();
}

bool Rayon::LibererRayon(int num)
{
    QSqlQuery query;
    query.prepare("Update RAYON set ETATRAYON=0 ,RESRAYON='' where NUMCAISSE=:num");
    query.bindValue(":num",num);
    return query.exec();
}

QSqlQueryModel *Rayon::afficherVideRay()
{
    QSqlQueryModel *m=new QSqlQueryModel();
    m->setQuery("select * from RAYON where ETATRAYON=0");
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Rayon"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("Type Rayon"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat Rayon"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("Res. Rayon"));
    return m;
}

QSqlQueryModel *Rayon::afficherReserveRay()
{
    QSqlQueryModel *m=new QSqlQueryModel();
    m->setQuery("select * from CAISSE where ETATCAISSE=1");
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Rayon"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("Type Rayon"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat Rayon"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("Res. Rayon"));
    return m;
}

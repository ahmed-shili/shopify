#include "caisse.h"


Caisse::Caisse(int NumCaisse,int EtatCaisse,QString CaisseRes,double CaisseInit,double CaisseRev)
{
    this->NumCaisse=NumCaisse;
    this->EtatCaisse=EtatCaisse;
    this->CaisseRes=CaisseRes;
    this->CaisseInit=CaisseInit;
    this->CaisseRev=CaisseRev;
}

int Caisse::get_numCaisse(){return NumCaisse;}

int Caisse::get_etatCaisse(){return EtatCaisse;}

QString Caisse::get_CaisseRes(){return CaisseRes;}

double Caisse::get_CaisseInit(){return CaisseInit;}

double Caisse::get_CaisseRev(){return CaisseRev;}

void Caisse::set_etatCaisse(int EtatCaisse){this->EtatCaisse=EtatCaisse;}

void Caisse::set_CaisseRes(QString CaisseRes){this->CaisseRes=CaisseRes;}

void Caisse::set_CaisseInit(double CaisseInit){this->CaisseInit=CaisseInit;}

bool Caisse::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CAISSE (NUMCAISSE,ETATCAISSE,CAISSERES,CAISSEINIT,CAISSEREV) "
                        "VALUES (:NUMCAISSE , :ETATCAISSE , :CAISSERES , :CAISSEINIT , :CAISSEREV)");
    query.bindValue(":NUMCAISSE",NumCaisse);
    query.bindValue(":ETATCAISSE",EtatCaisse);
    query.bindValue(":CAISSERES",CaisseRes);
    query.bindValue(":CAISSEINIT",CaisseInit);
    query.bindValue(":CAISSEREV",CaisseRev);
    return query.exec();
}

QSqlQueryModel *Caisse::afficher()
{
    QSqlQueryModel *m=new QSqlQueryModel();
    m->setQuery("select * from CAISSE");
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Caisse"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("Etat Caisse"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("Resp. Caisse"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("Caisse Initialle"));
    m->setHeaderData(4, Qt::Horizontal, QObject::tr("Revenue Caisse"));
    return m;
}

QSqlQueryModel *Caisse::rechercher(QString num)
{
    QSqlQuery query;
    QSqlQueryModel *m= new QSqlQueryModel();
    query.prepare("select * from CAISSE where NUMCAISSE like '"+num+"%'");
    query.exec();
    m->setQuery(query);
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Caisse"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("Etat Caisse"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("Resp. Caisse"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("Caisse Initialle"));
    m->setHeaderData(4, Qt::Horizontal, QObject::tr("Revenue Caisse"));
    return m;
}

bool Caisse::modifier(int a,int b,QString c,double d,int num)
{
    QSqlQuery query;
    query.prepare("Update caisse set NUMCAISSE=:NUMCAISSE ,ETATCAISSE=:ETATCAISSE,CAISSERES=:CAISSERES, CAISSEINIT=:CAISSEINIT where NUMCAISSE=:num");
    query.bindValue(":NUMCAISSE",a);
    query.bindValue(":ETATCAISSE",b);
    query.bindValue(":CAISSERES",c);
    query.bindValue(":CAISSEINIT",d);
    query.bindValue(":num",num);
    return query.exec();
}

bool Caisse::supprimer(int num)
{
    QSqlQuery query;
    query.prepare("Delete from caisse where NUMCAISSE=:num");
    query.bindValue(":num",num);
    return query.exec();
}

bool Caisse::affecterResC(int num, QString res)
{
    QSqlQuery query;
    query.prepare("Update caisse set ETATCAISSE=1,CAISSERES=:res where NUMCAISSE=:num");
    query.bindValue(":num",num);
    query.bindValue(":res",res);
    return query.exec();
}

bool Caisse::LibererCaisse(int num)
{
    QSqlQuery query;
    query.prepare("Update caisse set ETATCAISSE=0 ,CAISSERES='' where NUMCAISSE=:num");
    query.bindValue(":num",num);
    return query.exec();
}

bool Caisse::RevCaisse(int num)
{
    QSqlQuery query;
    QSqlQueryModel *m=new QSqlQueryModel();
    m->setQuery("select NUMCAISSE,CAISSEREV where NUMCAISSE=:num");
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMCAISSE"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("ETATCAISSE"));
    query.bindValue(":num",num);
    return query.exec();
}

QSqlQueryModel *Caisse::afficherVide()
{
    QSqlQueryModel *m=new QSqlQueryModel();
    m->setQuery("select * from CAISSE where ETATCAISSE=0");
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Caisse"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("Etat Caisse"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("Resp. Caisse"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("Caisse Initialle"));
    m->setHeaderData(4, Qt::Horizontal, QObject::tr("Revenue Caisse"));
    return m;
}

QSqlQueryModel *Caisse::afficherReserve()
{
    QSqlQueryModel *m=new QSqlQueryModel();
    m->setQuery("select * from CAISSE where ETATCAISSE=1");
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Caisse"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("Etat Caisse"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("Resp. Caisse"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("Caisse Initialle"));
    m->setHeaderData(4, Qt::Horizontal, QObject::tr("Revenue Caisse"));
    return m;
}

QSqlQueryModel *Caisse::afficherTri(QString tri)
{
    QSqlQueryModel *m=new QSqlQueryModel();
    m->setQuery("select * from CAISSE order by "+tri);
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Caisse"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("Etat Caisse"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("Resp. Caisse"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("Caisse Initialle"));
    m->setHeaderData(4, Qt::Horizontal, QObject::tr("Revenue Caisse"));
    return m;
}

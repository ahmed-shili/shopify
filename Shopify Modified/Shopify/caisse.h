#ifndef CAISSE_H
#define CAISSE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
class Caisse
{
    int NumCaisse,EtatCaisse;
    QString CaisseRes;
    double CaisseInit,CaisseRev;

public:
    Caisse(int a=0,int b=0,QString c="",double d=0,double e=0);

    int get_numCaisse();
    int get_etatCaisse();
    QString get_CaisseRes();
    double get_CaisseInit();
    double get_CaisseRev();
    void set_etatCaisse(int);
    void set_CaisseRes(QString);
    void set_CaisseInit(double);

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString);
    bool modifier(int a=0,int b=0,QString c="",double d=0,int num=-1);
    bool supprimer(int);
    bool affecterResC(int,QString);
    bool LibererCaisse(int);
    bool RevCaisse(int);

    QSqlQueryModel * afficherVide();
    QSqlQueryModel * afficherReserve();
    QSqlQueryModel * afficherTri(QString);
};

#endif // CAISSE_H

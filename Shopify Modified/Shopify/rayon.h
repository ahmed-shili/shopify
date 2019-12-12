#ifndef RAYON_H
#define RAYON_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

class Rayon
{
    int NumRayon,EtatRayon;
    QString TypeProd,ResRayon;
public:
    Rayon(int a=0, QString b="", int d=0, QString e="");

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString);
    bool modifier(int a=0,QString b=0,int c=0,QString d="",int num=-1);
    bool supprimer(int);
    QSqlQueryModel * afficherTri(QString);

    bool affecterResR(int,QString);
    bool LibererRayon(int);
    QSqlQueryModel * afficherVideRay();
    QSqlQueryModel * afficherReserveRay();
};

#endif // RAYON_H

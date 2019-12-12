#ifndef SALARIES_H
#define SALARIES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "conges.h"

class salaries
{
public:
    salaries();
    salaries(int,QString,QString,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    int get_id();
    QString get_email();
    QString get_post();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    int get_etat();
    QSqlQueryModel * recherche(QString valeur);
    bool modifier();
private:
    QString nom,prenom,email,post;
    int id,etat,somme,a,b,c,d,e,f;
};

#endif // SALARIES_H

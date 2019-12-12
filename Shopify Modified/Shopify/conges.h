#ifndef CONGES_H
#define CONGES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

class conges
{
public:
    conges();
    conges(int,QString,QString,QString,QDateTime,QDateTime,int);
    QString get_nom();
    QString get_prenom();
    int get_id();
    QDateTime get_debut();
    QDateTime get_fin();
    QString get_type();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * recherche(QString valeur);
    bool modifier(QString);
        bool modifier();
        bool modifierconges();
private:
    QString nom,prenom,type;
    QDateTime debut,fin;
    int id,etat ;
};

#endif // CONGES_H

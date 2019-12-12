#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseurs
{
public:
    fournisseurs();
    fournisseurs (QString,QString,int);
    QString get_nom();
    QString get_prenom();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     QSqlQueryModel * tri();
       QSqlQueryModel * rechercher(QString);
       bool modifierid(QString,int);
       bool modifiernom(QString,int);
       bool modifierprenom(QString,int);
private:
    QString nom,prenom;
    int id;
};

#endif // FOURNISSEURS_H

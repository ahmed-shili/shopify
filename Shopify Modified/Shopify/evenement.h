#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "articles.h"
#include <QDateTime>

class evenement
{
public:
    evenement();
    evenement(QString,QString,QDateTime,QDateTime);
    QSqlQueryModel * afficher(QString r);
    QSqlQueryModel * afficherj(QString);
    bool ajouter();
    bool supprimer(QString);
    QString get_type();
    QString get_saison();
    QDateTime get_date_debut();
    QDateTime get_date_fin();
    bool modifier(QString,QString,QDateTime,QDateTime);
    bool modifier2();

    QSqlQueryModel * affichertypee (QString typee);
    QSqlQueryModel * afficheraffecter(QString type);
    QSqlQueryModel *afficherTriE(QString );



private:
    QString typee,saison;
    articles produit_en_promo;
    articles cadeau;
    QDateTime date_debut,date_fin;

};

#endif // EVENEMENT_H





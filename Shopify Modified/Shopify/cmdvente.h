#ifndef CMDVENTE_H
#define CMDVENTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class cmdvente
{public:
    cmdvente();
    cmdvente(int,QString ,QString,int,int,int );
    cmdvente(int) ;
    QString get_nom();
    QString get_mode();
    int get_id();
    int get_num();
    int get_quantite() ;
    int get_prix () ;
    bool ajouter();
QSqlQueryModel* rechercher(QString id) ;
    QSqlQueryModel * afficher(QString r);
    bool supprimer(int);
    bool modifier(int  , QString  , QString,int,int,int );
    QSqlQueryModel *trieID() ;
    int stat_nbr_commande();
    int stat_nbr_commande1();
    int stat_nbr_commande2();
    int stat_nbr_commande3();

private:
    QString nom,mode_reglement;
    int id,num_article,quantite ;
int prix ;
};
#endif // CMDVENTE_H

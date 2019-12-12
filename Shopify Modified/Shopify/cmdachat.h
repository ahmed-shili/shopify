#ifndef CMDACHAT_H
#define CMDACHAT_H
#include <QSqlQueryModel>
#include <QString>
class cmdachat
{public:
    cmdachat();
    cmdachat(int,QString,int,int );
    QString get_nom();

    int get_id();
    int get_num();
    int get_quantite() ;
    int get_prix () ;
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int  ,  QString,int,int );
    QSqlQueryModel* rechercher1(QString id) ;


private:
    QString nom;
    int id,num_article,quantite ;

};

#endif // CMDACHAT_H

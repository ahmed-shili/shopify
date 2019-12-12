#ifndef CADEAUX_H
#define CADEAUX_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>

class cadeaux
{private:
    QString nom;
     int score;

public:
    cadeaux();
    cadeaux(QString,int);
       QString getnom();

             int getscore();
             void setnom(QString);
             void setscore(int);
             cadeaux getcad(int);
                   bool ajouter();
                   QSqlQueryModel *afficher(QString);
                    QSqlQueryModel *triecin();
                       bool supprimer (int);
                       QSqlQueryModel *chercher_cad(QString);
                       bool modifier();







};

#endif // CADEAUX_H

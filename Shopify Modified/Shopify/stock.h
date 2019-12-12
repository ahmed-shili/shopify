#ifndef STOCK_H
#define STOCK_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class stock
{
public:
    stock();
    stock(int,QString,QString,QString);
    QString get_type();
    QString get_marque();
     QString get_cat();
    int get_iden();
    bool ajouters();
    QSqlQueryModel * affichers();
    bool supprimers(int);
     QSqlQueryModel * tris();
       QSqlQueryModel * recherchers(QString);
         bool modifieriden(QString,int);
         bool modifiermarque(QString,int);
         bool modifiertype(QString,int);
         bool modifiercategorie(QString,int);

private:
    QString type,cat,marque;
    int iden;
};


#endif // STOCK_H

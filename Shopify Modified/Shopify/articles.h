#ifndef ARTICLES_H
#define ARTICLES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

class articles
{
public:
    articles();
    articles(int ,QString,int,QDateTime);
    QString get_type();
    QDateTime get_date_expiration();
    int get_numero();
    int get_quantites();

    void settype(QString);
    void setnumero(int);
    void setquantites(int);
    void setdate(QDateTime);

    bool ajouter();
    QSqlQueryModel * afficher(QString rech);
    bool supprimer(int);
    bool modifier(int,QString,int, QDateTime);
    bool modifier2();

    QSqlQueryModel * triequantites();
    QSqlQueryModel * trienumero();
    QSqlQueryModel * afficherid (QString);
    QSqlQueryModel *afficherTriA(QString );
    articles getarticle(int numero);



private:
    QString type;
    int numero,quantites;
    QDateTime date_expiration;
};

#endif // ARTICLES_H

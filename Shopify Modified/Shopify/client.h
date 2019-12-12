#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class client
{ private:
    QString nom,prenom,adresse;
    int cin;
public:
    client();
    client(int,QString,QString ,QString );
       QString getnom();
             QString getprenom();
             QString getadresse();
             void setcin(int);
             void setnom(QString);
             void setprenom(QString);
             void setadresse(QString);
             int getcin();
                   bool ajouter();

                   QSqlQueryModel *afficher(QString r);

                   QSqlQueryModel *triecin();

                   bool modifier();
                       bool supprimer (int);
                       client getclient(int);
                        QSqlQueryModel * rechercher(QString );



};

#endif // CLIENT_H

#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QString>

class Connexion
{
private:
    QSqlDatabase db;
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();

};

#endif // CONNEXION_H

#include "cmdvente.h"
#include <QDebug>
#include <QDate>
cmdvente::cmdvente()
{
id=0;
nom="";
mode_reglement="";

}
cmdvente::cmdvente(int id,QString nom ,QString mode_reglement,int num_article,int quantite,int prix)
{
  this->id=id;
  this->nom=nom;
  this->mode_reglement=mode_reglement;
    this->num_article=num_article;
    this->quantite=quantite;
    this->prix=prix;

}
QString cmdvente::get_nom(){return  nom;}
QString cmdvente::get_mode(){return mode_reglement;}
int cmdvente::get_id(){return  id;}
int cmdvente::get_num(){return  num_article;}
int  cmdvente::get_quantite() {return quantite;}
int cmdvente:: get_prix (){return prix ;} ;
bool cmdvente::ajouter()


{
QSqlQuery query;
QString res= QString::number(id);
QString re= QString::number(num_article);
QString r= QString::number(quantite);
QString rr= QString::number(prix);
query.prepare("INSERT INTO CMDVENTE(ID,NOM, MODE_REGLEMENT,NUM_ARTICLE,QUANTITE,PRIX) "
                    "VALUES (:id, :nom, :mode_reglement,:num_article,:quantite,:prix)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":mode_reglement", mode_reglement);
query.bindValue(":num_article", re);
query.bindValue(":quantite", r);
query.bindValue(":prix", rr);

return    query.exec();
}


QSqlQueryModel * cmdvente::afficher(QString r)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CMDVENTE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("mode_reglement"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_article"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

bool cmdvente::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from CMDVENTE where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool cmdvente::modifier(int id , QString nom , QString mode_reglement ,int num_article,int quantite,int prix)
{
    QSqlQuery query;

query.prepare("Update CMDVENTE set id=:id,nom=:nom,mode_reglement=:mode_reglement,num_article=:num_article,quantite=:quantite,prix=:prix where id=: id");
query.bindValue(":id", get_id());
query.bindValue(":nom", get_nom());
query.bindValue(":mode_reglement", get_mode());
query.bindValue(":quantite", get_quantite());
query.bindValue(":prix", get_prix());
query.bindValue(":num_article", get_num());



    return query.exec();
}

QSqlQueryModel * cmdvente::trieID()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select *   from CMDVENTE order by ID");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("mode_reglement"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_article"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));

        return model;
    }
int cmdvente ::stat_nbr_commande(){

    QSqlQuery affiche;
    int v;
    affiche.prepare("select count(*) from CMDVENTE where ID>0" );
    affiche.exec();
    while(affiche.next()) v=affiche.value(0).toInt();

    return v;
}


int cmdvente ::stat_nbr_commande1(){

    QSqlQuery affiche;
    int a;
    affiche.prepare("select count(*) from CMDVENTE where ID>0'" );
    affiche.exec();
    while(affiche.next()) a=affiche.value(0).toInt();

    return a;


}

int cmdvente ::stat_nbr_commande2(){

    QSqlQuery affiche;
    int a;
    affiche.prepare("select count(*) from CMDVENTE where ID>0 " );
    affiche.exec();
    while(affiche.next()) a=affiche.value(0).toInt();

    return a;


}


int cmdvente ::stat_nbr_commande3(){

    QSqlQuery affiche;
    int a;
    affiche.prepare("select count(*) from Evenement where ID>0'" );
    affiche.exec();
    while(affiche.next()) a=affiche.value(0).toInt();

    return a;


}
QSqlQueryModel *cmdvente::rechercher(QString id){

    QSqlQuery query;
    query.prepare("select * from CMDVENTE where ID like '%"+id+"%'");
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("mode_reglement"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_article"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));

        return model;

}




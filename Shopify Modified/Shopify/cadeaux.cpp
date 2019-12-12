
#include "cadeaux.h"
#include<QMessageBox>
cadeaux::cadeaux()
{
nom="";
//type="";
score=0;
}
cadeaux::cadeaux(QString nom,int score){

    this->nom=nom;
   // this->type=type;
    this->score=score;
}
QString cadeaux::getnom(){
    return nom;
}
/*QString cadeaux::gettype(){
    return type;
}*/
int cadeaux::getscore(){
    return score;
}
void cadeaux::setnom(QString n){
    nom=n;
}

void cadeaux::setscore(int s){
    score=s;
}
cadeaux cadeaux::getcad(int score){
    QSqlQuery query;
        QString res= QString::number(score);
        query.prepare("Select *from CADEAUX where SCORE = :SCORE ");
        query.bindValue(":SCORE", res);
        cadeaux eq;
        if(query.exec())
        {
            QMessageBox::information(nullptr, QObject::tr("modifier un cadeau"),
                        QObject::tr("client trouvé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

            while(query.next())
            {
                 eq.setnom(query.value(0).toString());
                 eq.setscore(query.value(1).toInt());


            }

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Rechercher un cadeau"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }

        return  eq ;
}
bool cadeaux::ajouter(){

  QSqlQuery query;

    query.prepare("INSERT INTO CADEAUX (NOM,SCORE)"
                  "VALUES (:NOM, :SCORE)");

    query.bindValue(":NOM", nom);
    query.bindValue(":SCORE", score);

  //  query.bindValue(":TYPE", type);


    return    query.exec();


}


QSqlQueryModel *cadeaux::afficher(QString r){

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery(r);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SCORE"));


    return  model;



}




bool cadeaux::supprimer(int score){

    QSqlQuery query;
    query.prepare("Delete from CADEAUX where SCORE= :SCORE");
    query.bindValue(":SCORE", score);
    return query.exec();



}


QSqlQueryModel * cadeaux::triecin()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from  CADEAUX order by SCORE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SCORE"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));


    return model;
}


QSqlQueryModel * cadeaux::chercher_cad(QString nom){
   QSqlQuery query;

  query.prepare("select * from CADEAUX where NOM like '%"+nom+"%'");
  query.exec();
         QSqlQueryModel * model= new QSqlQueryModel();
          model->setQuery(query);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("SCORE"));
               return model;


}

bool cadeaux::modifier()
{
    QSqlQuery query;

    query.prepare("Update CADEAUX set NOM= :NOM ,SCORE= :SCORE where SCORE= :SCORE");

    query.bindValue(":NOM", nom);


    query.bindValue(":SCORE", score);



    return query.exec();
}






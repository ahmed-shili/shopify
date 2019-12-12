#include "admin.h"
#include "ui_admin.h"
#include"client.h"
#include<QtDebug>
#include"cadeaux.h"
#include<QMessageBox>
#include "cmdvente.h"
#include "statistique.h"
#include "cmdachat.h"
Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    popUp = new PopUp();

    cam = new QCamera(this);
    camview = new QCameraViewfinder(this);
    imgcam = new QCameraImageCapture(cam,this);
    cam->setViewfinder(camview);
    camlayout = new QVBoxLayout;
    camlayout->addWidget(camview);
    ui->CamWidget->setLayout(camlayout);


    ui->TableCaisse->setModel(c.afficher());
    ui->TableAffecter->setModel(c.afficherVide());
    ui->TableLiberer->setModel(c.afficherReserve());
    ui->tabevenements_2->setModel(tmpevenements.afficher("select * from tabevenements"));
    ui->tableView_cad->setModel(tmpcad.afficher("select *from CADEAUX"));
    ui->TableRayon->setModel(r.afficher());
    ui->TableAffecter_R->setModel(r.afficherVideRay());
    ui->TableLiberer_R->setModel(r.afficherReserveRay());
    ui->tv_gestions->setModel(s.afficher());
    ui->tabarticles_22->setModel(tmparticles.afficher("select * from tabarticles"));
    ui->tabevenements->setModel(tmpevenements.afficher("select * from tabevenements"));
    connect(ui->sendcl, SIGNAL(clicked()),this, SLOT(sendMail()));
 connect(ui->send, SIGNAL(clicked()),this, SLOT(sendMail1()));
    ui->tabetudiant->setModel(tmp.afficher("select * from CMDVENTE"));
    ui->tableView->setModel(tmp1.afficher());
    ui->tvcongesSTW->setModel(co.afficher());


    QRegExp rx("[A-Za-z_]+");//[A-Za-z0-9_]
        QRegExp rx1("[0-9_]+");
        QValidator *validator = new QRegExpValidator(rx, this);
        QValidator *validator2 = new QRegExpValidator(rx1, this);
        ui->lineEdit_nom->setValidator(validator);
         ui->lineEdit_prenom->setValidator(validator);
          ui->lineEdit_adresse->setValidator(validator);
           ui->le_noms->setValidator(validator);
           ui->le_prenoms->setValidator(validator);
           ui->le_posts->setValidator(validator);
           ui->lineEdit_type->setValidator(validator);
           ui->lineEdit_type_5->setValidator(validator);
           ui->lineEdit_saison_3->setValidator(validator);
           ui->type_supp_rech_mod->setValidator(validator);
           ui->affecter_selon_type->setValidator(validator);
           ui->le_ids->setValidator(validator2);
           ui->IDAfficherS->setValidator(validator2);
           ui->Le_idconges->setValidator(validator2);
           ui->le_salairehs->setValidator(validator2);
           ui->le_salarienbs->setValidator(validator2);
           ui->le_primes->setValidator(validator2);
           ui->le_taxes->setValidator(validator2);
           ui->le_salaireid->setValidator(validator2);
           ui->le_salarienet->setValidator(validator2);
           ui->le_salariebrut->setValidator(validator2);
           ui->le_nbrtravail->setValidator(validator2);
           ui->lineEdit_numeo->setValidator(validator2);
           ui->lineEdit_quantites->setValidator(validator2);
           ui->numero_sup_rech_mod->setValidator(validator2);
           ui->lineEdit_Nom->setValidator(validator);
           ui->lineEdit_Prenom->setValidator(validator);
           ui->lineEdit_ID->setValidator(validator2);
           ui->lineEdit_4->setValidator(validator2);
           ui->lineEdit_5->setValidator(validator);
           ui->lineEdit_6->setValidator(validator);
           ui->lineEdit_7->setValidator(validator);
           ui->lineEdit_mi->setValidator(validator2);
           ui->lineEdit_mi_4->setValidator(validator2);
           ui->lineEdit_8->setValidator(validator2);
           ui->search->setValidator(validator);
           ui->lineEdit_2->setValidator(validator);
           ui->lineEdit_id_3->setValidator(validator2);


}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_AjouterC_clicked()
{
    int num=ui->numAjouter->text().toInt();
    QString Res=ui->ResAjouter->text();
    double CInit=ui->CInitAjouter->text().toDouble();
    int etat;
    if(ui->EtatVideAjouter->isChecked())
        etat=0;
    else etat=1;

    Caisse NewC(num,etat,Res,CInit,0);

    if(NewC.ajouter()){
    popUp->setPopupText("Caisse ajoutée");
    popUp->show();
}
         else{
             popUp->setPopupText("Caisse n'est pas ajoutée");
             popUp->show();}
    ui->TableCaisse->setModel(c.afficher());
    ui->TableAffecter->setModel(c.afficherVide());
}

void Admin::on_AjouterR_clicked()
{
    int num=ui->numAjouter_Ray->text().toInt();
    QString type=ui->TypeAjouter_Ray->currentText();
    int etat;
    if(ui->EtatVideAjouter_Ray->isChecked())
        etat=0;
    else etat=1;
    QString res=ui->ResAjouter_Ray->text();
    Rayon NewR(num,type,etat,res);

    if(NewR.ajouter()){
    popUp->setPopupText("Rayon ajoutée");
    popUp->show();}
         else{
             popUp->setPopupText("Rayon n'est pas ajoutée");
             popUp->show();}
    ui->TableRayon->setModel(r.afficher());
}

void Admin::on_numAfficherC_textChanged(const QString &arg1)
{
    ui->TableCaisse->setModel(c.rechercher(arg1));
    if(arg1=="")
        ui->TableCaisse->setModel(c.afficher());
}

void Admin::on_TriC_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0:
            ui->TableCaisse->setModel(c.afficher());
        break;
    case 1:
            ui->TableCaisse->setModel(c.afficherTri("NUMCAISSE"));
        break;
    case 2:
        ui->TableCaisse->setModel(c.afficherTri("ETATCAISSE"));
        break;
    case 3:
        ui->TableCaisse->setModel(c.afficherTri("CAISSERES"));
        break;
    case 4:
        ui->TableCaisse->setModel(c.afficherTri("CAISSEINIT"));
        break;
    case 5:
        ui->TableCaisse->setModel(c.afficherTri("CAISSEREV"));
        break;
    default:
        ui->TableCaisse->setModel(c.afficher());
    }
}

void Admin::on_numAfficher_R_textChanged(const QString &arg1)
{
    ui->TableRayon->setModel(r.rechercher(arg1));
    if(arg1=="")
        ui->TableRayon->setModel(r.afficher());
}

void Admin::on_Tri_R_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0:
            ui->TableRayon->setModel(r.afficher());
        break;
        case 1:
            ui->TableRayon->setModel(r.afficherTri("NUMRAYON"));
        break;
        case 2:
            ui->TableRayon->setModel(r.afficherTri("TYPEPROD"));
        break;
        case 3:
            ui->TableRayon->setModel(r.afficherTri("ETATRAYON"));
        break;
        case 4:
            ui->TableRayon->setModel(r.afficherTri("RESRAYON"));
        break;
        default:
            ui->TableRayon->setModel(r.afficher());
    }
}

void Admin::on_EtatVideAjouter_Ray_clicked()
{
    ui->ResAjouter_Ray->setText("");
    ui->ResAjouter_Ray->setDisabled(true);
    ui->ChoiResAjouter_Ray->setDisabled(true);
    ui->raR->setDisabled(true);
}

void Admin::on_EtatGuarAjouter_Ray_clicked()
{
    ui->ResAjouter_Ray->setEnabled(true);
    ui->ChoiResAjouter_Ray->setEnabled(true);
    ui->raR->setEnabled(true);
}

void Admin::on_EtatVideAjouter_clicked()
{
    ui->ResAjouter->setText("");
    ui->ResAjouter->setDisabled(true);
    ui->ChoiResAjouter->setDisabled(true);
    ui->ra->setDisabled(true);
}

void Admin::on_EtatResAjouter_clicked()
{
    ui->ResAjouter->setEnabled(true);
    ui->ChoiResAjouter->setEnabled(true);
    ui->ra->setEnabled(true);
}

void Admin::on_Affecter_clicked()
{
    int num=ui->numAffecter->text().toInt();
    QString res=ui->ResAffecter->text();

    if(c.affecterResC(num,res))
         {
             popUp->setPopupText("Responsable affecté");
             popUp->show();

         }
         else
{popUp->setPopupText("Responsable n'est pas affecté");
             popUp->show();}
    ui->TableCaisse->setModel(c.afficher());
    ui->TableAffecter->setModel(c.afficherVide());
    ui->TableLiberer->setModel(c.afficherReserve());
}

void Admin::on_Liberer_clicked()
{
    int num=ui->numLiberer->text().toInt();

    if(c.LibererCaisse(num))
         {
             popUp->setPopupText("Caisse libéré");
             popUp->show();

         }
         else
    {popUp->setPopupText("Caisse n'est pas libéré");
    popUp->show();}

    ui->TableCaisse->setModel(c.afficher());
    ui->TableAffecter->setModel(c.afficherVide());
    ui->TableLiberer->setModel(c.afficherReserve());
}

void Admin::on_SupprimerC_clicked()
{
    int num=ui->numAfficherC->text().toInt();

    if(c.supprimer(num))
         {
             popUp->setPopupText("Caisse Supprimée");
             popUp->show();

         }
         else
            {             popUp->setPopupText("Caisse n'est pas Supprimée");
        popUp->show();}
    ui->TableCaisse->setModel(c.afficher());
    ui->TableAffecter->setModel(c.afficherVide());
    ui->TableLiberer->setModel(c.afficherReserve());
}

void Admin::on_SupprimerR_clicked()
{
    int num=ui->numAfficherR->text().toInt();

    if(r.supprimer(num))
    {             popUp->setPopupText("Rayon Supprimé");
        popUp->show();}
         else{             popUp->setPopupText("Rayon n'est pas Supprimé");
        popUp->show();}

    ui->TableRayon->setModel(r.afficher());
}

void Admin::on_numAfficherR_textChanged(const QString &arg1)
{
    ui->TableRayon->setModel(r.rechercher(arg1));
    if(arg1=="")
        ui->TableRayon->setModel(r.afficher());
}

void Admin::on_AjouterSTW_clicked()
{
    int id = ui->le_ids->text().toInt();
    QString nom= ui->le_noms->text();
    QString prenom= ui->le_prenoms->text();
    QString email= ui->le_emails->text();
    QString post= ui->le_posts->text();
    int etat=0;
     salaries e(id, nom, prenom,email, post,etat);

  bool test=e.ajouter();
  if(test)
{ui->tv_gestions->setModel(s.afficher());//refresh

      popUp->setPopupText("Salaries ajouté");
             popUp->show();
}
  else
      { popUp->setPopupText("Erreur");
          popUp->show();}


}

void Admin::on_IDAfficherS_textChanged(const QString &arg1)
{
    ui->tv_gestions->setModel(s.recherche(arg1));
}

void Admin::on_SupprimerSTW_clicked()
{
    int id = ui->IDAfficherS->text().toInt();
    bool test=s.supprimer(id);
    if(test)
   { ui->tv_gestions->setModel(s.afficher());//refresh

        popUp->setPopupText("salaries supprimé");
               popUp->show();

    }
    else

{      popUp->setPopupText("Erreur !");
            popUp->show();}

}

void Admin::on_Le_idconges_textChanged(const QString &arg1)
{
    ui->tvcongesSTW->setModel(co.recherche(arg1));
}


void Admin::on_calculersalaire_clicked()
{
    int a=ui->le_salairehs->text().toInt();
    int b=ui->le_salarienbs->text().toInt();
    int c=ui->le_primes->text().toInt();
    int d=ui->le_taxes->text().toInt();
    int e=ui->sb_nbabss->text().toInt();
    int f=ui->sb_nbsups->text().toInt();
    int somme=(a*b)+c-d-(e*a)+(f*a);
    ui->le_salaires->setText( QString::number(somme) );
}

int Admin::on_fichedepaie_clicked()
{
    QPrinter printer;
         printer.setOutputFormat(QPrinter::PdfFormat);
         printer.setOutputFileName("fiche_de_paie.pdf");
         QPainter painter;
         if (! painter.begin(&printer)) { // failed to open file
             qWarning("failed to open file, is it writable?");
             return 1;
         }
         painter.drawText(306, 20, "Fiche De Paie");
         painter.drawText(10, 40, "ID du salaries:");
         painter.drawText(200, 40, ui->le_salaireid->text() );
         painter.drawText(10, 80, "Salaire NET");
         painter.drawText(200, 80,ui->le_salarienet->text());
         painter.drawText(10, 120, "Salaire brut");
         painter.drawText(200, 120,ui->le_salariebrut->text());
         painter.drawText(10, 160, "Nbre de hours travaillées");
         painter.drawText(200, 160,ui->le_nbrtravail->text());
         painter.drawText(10, 200, "Nbre du hour absent");
         painter.drawText(200, 200,ui->sb_nbabss1->text());
         painter.drawText(10, 240, "Nbre du hour supplementaire");
         painter.drawText(200, 240,ui->sb_nbsups1->text());
         if (! printer.newPage()) {
             qWarning("failed in flushing page to disk, disk full?");
             return 1;
         }
         painter.drawText(10, 10, "Test 2");
         painter.end();
}

void Admin::on_ajouter_articles_clicked()
{
    int numero = ui->lineEdit_numeo->text().toInt();
    QString typee= ui->lineEdit_type->text();
    int quantites = ui->lineEdit_quantites->text().toInt();
    QDateTime date_expiration= ui->lineEdit_date_expiration->dateTime();
  articles ar(numero,typee,quantites,date_expiration);
  bool test=ar.ajouter();
  if(test)
{ui->tabarticles_22->setModel(tmparticles.afficher("select * from tabarticles"));//refresh
popUp->setPopupText("Article ajouté");
       popUp->show();

}
  else
  {        popUp->setPopupText("Erreur !");
      popUp->show();}
}

void Admin::on_supprimer_articles_clicked()
{
    int numero = ui->numero_sup_rech_mod->text().toInt();
    bool test=tmparticles.supprimer(numero);
    if(test)
    {ui->tabarticles_22->setModel(tmparticles.afficher("select * from tabarticles"));//refresh
        popUp->setPopupText("article supprimé");
                popUp->show();

    }
    else
    {        popUp->setPopupText("Erreur !");
        popUp->show();}
}

void Admin::on_numero_sup_rech_mod_textChanged(const QString &arg1)
{
    ui->tabarticles_22->setModel(tmparticles.afficherid(arg1));

}

void Admin::on_ajout_evenement_clicked()
{
    QString typee= ui->lineEdit_type_5->text();
    QString saison= ui->lineEdit_saison_3->text();
    QDateTime date_debut= ui->lineEdit_date_debut_3->dateTime();
    QDateTime date_fin= ui->lineEdit_date_fin_3->dateTime();

  evenement eve(typee,saison,date_debut,date_fin);

  bool test=eve.ajouter();
  if( test)
{ui->tabevenements->setModel(tmpevenements.afficher("select * from tabevenements"));//refresh
popUp->setPopupText("Evenement ajouté");
      popUp->show();

}
  else
  {        popUp->setPopupText("Erreur !");
      popUp->show();}
}

void Admin::on_type_supp_rech_mod_textChanged(const QString &arg1)
{
    ui->tabevenements->setModel(tmpevenements.affichertypee(arg1));

}

void Admin::on_supprimer_eve_clicked()
{
    //supp evenement selon type
    QString typee= ui->type_supp_rech_mod->text();
    bool test=tmpevenements.supprimer(typee);
    if(test)
    {ui->tabevenements->setModel(tmpevenements.afficher("select * from tabevenements"));//refresh
        popUp->setPopupText("evenement supprimé");
              popUp->show();}


    else
    {        popUp->setPopupText("Erreur !");
        popUp->show();}

}

void Admin::on_pb_affecter_clicked()
{
    ui->tabevenements_2->setModel(tmpevenements.afficherj(ui->affecter_selon_type->text()));

}

void Admin::on_supprimer_evenement_clicked()
{
    //supp evenement selon type
    QString typee= ui->type_supp_rech_mod->text();
    bool test=tmpevenements.supprimer(typee);
    if(test)
    {ui->tabevenements->setModel(tmpevenements.afficher("select * from tabevenements"));//refresh
        popUp->setPopupText("evenement supprimé");
                popUp->show();

    }
    else
    {        popUp->setPopupText("Erreur !");
        popUp->show();}
}

void Admin::on_pushButton_4_ajouterclient_clicked()
{
    int cin = ui->lineEdit_cin->text().toInt();
       QString nom= ui->lineEdit_nom->text();
          QString prenom= ui->lineEdit_prenom->text();

          QString adresse=ui->lineEdit_adresse->text();

        client e(cin,nom,prenom,adresse);
        bool test=e.ajouter();
        if(test)
      {ui->tabetudiant->setModel(tmpclient.afficher("select *from CLIENT_CRUD"));//refresh
            popUp->setPopupText("client ajouté");
                        popUp->show();

      }
        else
        {        popUp->setPopupText("Erreur !");
            popUp->show();}

}



void Admin::on_supprimeclient_clicked()
{
    int cin = ui->lineEdit_7->text().toInt();
        bool test=tmpclient.supprimer(cin);
        if(test)
        {ui->tabetudiant->setModel(tmpclient.afficher("select * from CLIENT_CRUD"));//refresh
                popUp->setPopupText("client supprimé");
            popUp->show();}


        else
        {        popUp->setPopupText("Erreur !");
            popUp->show();}




}

void Admin::on_pushButton_trier_clicked()
{

    // ui->tabetudiant->setModel(tmpclient.triecin());
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from CLIENT_CRUD order by CIN");
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
     ui->tabetudiant->setModel(model);
}

void Admin::on_lineEdit_5_textChanged(const QString &arg1)
{    client c;
    // QString nom=ui->lineEdit_nom->text();
     ui->tabetudiant->setModel(c.rechercher(arg1));

}

void Admin::on_lineEdit_7_textChanged(const QString &arg1)
{
    QString r;
    r="select *from CLIENT_CRUD where CIN like "+arg1;
    ui->tabetudiant->setModel(tmpclient.afficher(r));
}

void Admin::on_cadeauajouter_clicked()
{
    QString nom= ui->lineEdit_nomcad->text();
        int score = ui->lineEdit_scorecad->text().toInt();


         cadeaux e(nom,score);
         bool test=e.ajouter();
         if(test)
       {ui->tableView_cad->setModel(tmpcad.afficher("select *from CADEAUX"));//refresh
                popUp->setPopupText("cadeau ajouté");
            popUp->show();

       }
         else
        {        popUp->setPopupText("Erreur !");
            popUp->show();}
}


void Admin::on_supprimer_cadeau_clicked()
{
    int score= ui->lineEdit_rechcad->text().toInt();
           bool test=tmpcad.supprimer(score);
           if(test)
           {ui->tableView_cad->setModel(tmpcad.afficher("select *from CADEAUX"));//refresh
popUp->setPopupText("cadeau supprimé");
            popUp->show();

           }
           else
        {        popUp->setPopupText("Erreur !");
            popUp->show();
           }
}

void Admin::on_comboBox_2_activated(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
        if(arg1=="nom")


            model->setQuery("select * from CADEAUX order by NOM");
        if(arg1=="score")
            model->setQuery("select * from CADEAUX order by SCORE");
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("SCORE"));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
       ui->tableView_cad->setModel(model);
}






void Admin::on_lineEdit_rechcad_textChanged(const QString &arg1)
{ QString r;
    r="select *from CADEAUX where SCORE like '"+arg1+"'";
    ui->tableView_cad->setModel(tmpcad.afficher(r));

}

void Admin::on_lineEdit_recher_cad_textChanged(const QString &arg1)
{cadeaux cad;
    ui->tableView_cad->setModel(cad.chercher_cad(arg1));
}



void Admin::on_tabetudiant_activated(const QModelIndex &index)
{
    QString val=ui->tabetudiant->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from CLIENT_CRUD where CIN='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or ADRESSE='"+val+"' ");
    if (qry.exec( ))
    {
                  while(qry.next())
                    {
                        ui->lineEdit_nom->setText(qry.value(0).toString());
                        ui->lineEdit_prenom->setText(qry.value(1).toString());
                        ui->lineEdit_adresse->setText(qry.value(2).toString());
                        ui->lineEdit_cin->setText(qry.value(3).toString());


                    }
                }
}



void Admin::on_modifier_client_clicked()
{
    int cin=ui->lineEdit_cin->text().toInt();
           QString nom=ui->lineEdit_nom->text();
           QString prenom =ui->lineEdit_prenom->text();
           QString adresse =ui->lineEdit_adresse->text();

          // bool test=tmpclient.modifier();
           client e(cin,nom,prenom,adresse);
           bool test=e.modifier();

           if(test){ui->tabetudiant->setModel(tmpclient.afficher("select * from CLIENT_CRUD"));
 popUp->setPopupText("successful");
            popUp->show();
           }
           else
       {        popUp->setPopupText("Erreur !");
            popUp->show();
           }
}

void Admin::on_tableView_cad_activated(const QModelIndex &index)
{
    QString val=ui->tableView_cad->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from CADEAUX where SCORE='"+val+"'");
    if (qry.exec( ))
    {
                  while(qry.next())
                    {
                        ui->lineEdit_nomcad->setText(qry.value(0).toString());
                        ui->lineEdit_scorecad->setText(qry.value(1).toString());


                    }
                }
}

void Admin::on_modif_cad_clicked()
{
    int score=ui->lineEdit_scorecad->text().toInt();
           QString nom=ui->lineEdit_nomcad->text();


          // bool test=tmpclient.modifier();
           cadeaux e(nom,score);

           if(e.modifier()){ui->tableView_cad->setModel(e.afficher("select * from CADEAUX"));
           popUp->setPopupText("successful");
                      popUp->show();}

          else{
               popUp->setPopupText("ERROR !");
                          popUp->show();
           }
}

void Admin::on_trie_client_currentIndexChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
      if(arg1=="Cin")
          model->setQuery("select * from CLIENT_CRUD order by CIN");
      if(arg1=="Nom")
          model->setQuery("select * from CLIENT_CRUD order by NOM");
      if(arg1=="Prenom")
          model->setQuery("select * from CLIENT_CRUD order by PRENOM");
      if(arg1=="Adresse")
          model->setQuery("select * from CLIENT_CRUD order by ADRESSE");
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
      ui->tabetudiant->setModel(model);
}



void Admin::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString mode_reglement= ui->comboBox->currentText();

    int num_article = ui->lineEdit_num->text().toInt();
    int quantite = ui->lineEdit_quantite->text().toInt();
    int prix = ui->lineEdit_prix->text().toInt();


  cmdvente e(id,nom,mode_reglement,num_article,quantite,prix);
  bool test=e.ajouter();
  if(test)
{ui->tabe->setModel(tmp.afficher("select * from CMDVENTE"));//refresh

}


}


void Admin::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id->text().toInt();
bool test=tmp.supprimer(id);
if(test)
{ui->tabe->setModel(tmp.afficher("select * from CMDVENTE"));//refresh

}


}
void Admin::on_pb_modifier_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
     QString mode_reglement= ui->comboBox->currentText();

    int num_article = ui->lineEdit_num->text().toInt();

    int quantite = ui->lineEdit_quantite->text().toInt();
    float prix = ui->lineEdit_prix->text().toFloat();


  cmdvente e(id,nom,mode_reglement,num_article,quantite,prix);

  bool test=e.modifier(id ,nom, mode_reglement,num_article,quantite,prix);
  if(test)
{ui->tabe->setModel(tmp.afficher("select * from CMDVENTE"));

}


}
void Admin::on_pb_trier_clicked()
{
    ui->tabe->setModel(tmp.trieID());

}
void Admin::on_pb_statistique_clicked()
{
 statistique stat ;

    stat.setModal(true) ;

    stat.exec();
}
void Admin::on_pb_ajouter1_clicked()
{
    int id = ui->lineEdit_id_4->text().toInt();
    QString nom= ui->lineEdit_nom_4->text();


    int num_article = ui->lineEdit_num_3->text().toInt();
    int quantite = ui->lineEdit_quantite_3->text().toInt();


  cmdachat e(id,nom,num_article,quantite);
  bool test=e.ajouter();
  if(test)
{ui->tableView->setModel(tmp1.afficher());


}


}

void Admin::on_pb_supprimer1_clicked()
{
int id = ui->lineEdit_id_4->text().toInt();
bool test=tmp1.supprimer(id);
if(test)
{ui->tableView->setModel(tmp1.afficher());//refresh

}



}
void Admin::on_pb_modifier1_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();


    int num_article = ui->lineEdit_num->text().toInt();

    int quantite = ui->lineEdit_quantite->text().toInt();



  cmdachat e(id,nom,num_article,quantite);

  bool test=e.modifier(id ,nom ,num_article,quantite);
  if(test)
{ui->tableView->setModel(tmp1.afficher());//refresh



}}
  void Admin::on_lineEdit_6_textChanged(const QString &arg1)
  {    cmdvente e;
      // QString nom=ui->lineEdit_nom->text();
       ui->tabe->setModel(e.rechercher(arg1));

  }

  void Admin::on_lineEdit_9_textChanged(const QString &arg2)
  {    cmdachat e;
      // QString nom=ui->lineEdit_nom->text();
       ui->tableView->setModel(e.rechercher1(arg2));

  }


void Admin::sendMail()
{
    Smtp *smtp= new Smtp("yasmine.manita@esprit.tn", "181JFT1294","smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("yasmine.manita@esprit.tn",ui->mailcl->text(), ui->objcl->text(),ui->msgcl->toPlainText());
}

void Admin::mailSent(QString status)
{
    if(status == "Message sent")
    {
         popUp->setPopupText("Message sent");
         popUp->show();
     }
}
void Admin::sendMail1()
{
    Smtp *smtp= new Smtp("ons.trabelsi@esprit.tn", "171JFT1294","smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent1(QString)));


    smtp->sendMail("ons.trabelsi@esprit.tn",ui->rcpt->text(), ui->subject->text(),ui->msg->toPlainText());
}

void Admin::mailSent1(QString status)
{
    if(status == "Message sent")
    {
        popUp->setPopupText("Message sent");
        popUp->show();
    }
}

void Admin::on_ConfirmerS_clicked()
{
    int etat;
    QString nom,prenom,type;
    QDateTime debut,fin;
    int id = ui->Le_idconges->text().toInt();
    if(ui->radioButton_validerS->isChecked())
       etat=1;
    else etat=0;
    conges c(id,nom,prenom,type,debut,fin,etat);
    c.modifierconges();
  ui->tvcongesSTW->setModel(co.afficher());//refresh
}

void Admin::on_TriA_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0:
            ui->tabarticles_22->setModel(tmparticles.afficher("select * from tabarticles"));
        break;
        case 1:
            ui->tabarticles_22->setModel(tmparticles.afficherTriA("NUMERO"));
        break;
        case 2:
            ui->tabarticles_22->setModel(tmparticles.afficherTriA("TYPE"));
        break;
        case 3:
            ui->tabarticles_22->setModel(tmparticles.afficherTriA("QUANTITES"));
        break;
        case 4:
            ui->tabarticles_22->setModel(tmparticles.afficherTriA("DATE_EXPIRATION"));
        break;
        default:
            ui->tabarticles_22->setModel(tmparticles.afficher("select * from tabarticles"));
    }
}

void Admin::on_TriA_2_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0:
            ui->tabevenements->setModel(tmpevenements.afficher("select * from tabevenements"));
        break;
        case 1:
            ui->tabevenements->setModel(tmpevenements.afficherTriE("TYPEE"));
        break;
        case 2:
            ui->tabevenements->setModel(tmpevenements.afficherTriE("SAISON"));
        break;
        case 3:
            ui->tabevenements->setModel(tmpevenements.afficherTriE("DATE_DEBUT"));
        break;
        case 4:
            ui->tabevenements->setModel(tmpevenements.afficherTriE("DATE_FIN"));
        break;
        default:
            ui->tabevenements->setModel(tmpevenements.afficher("select * from tabevenements"));
    }
}

void Admin::on_tv_gestions_activated(const QModelIndex &index)
{

    QString val=ui->tv_gestions->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from salaries where id='"+val+"' or nom='"+val+"' or prenom='"+val+"' or email='"+val+"' or post='"+val+"'");
    if (qry.exec( ))
    {
                  while(qry.next())
                    {
                        ui->le_ids->setText(qry.value(0).toString());
                        ui->le_noms->setText(qry.value(1).toString());
                        ui->le_prenoms->setText(qry.value(2).toString());
                        ui->le_emails->setText(qry.value(3).toString());
                        ui->le_posts->setText(qry.value(4).toString());

                    }
                }


}

void Admin::on_ModiferSTW_clicked()
{
    int id = ui->le_ids->text().toInt();
    QString nom= ui->le_noms->text();
    QString prenom= ui->le_prenoms->text();
    QString email= ui->le_emails->text();
    QString post= ui->le_posts->text();
    int etat=0;
     salaries e(id, nom, prenom,email, post,etat);

  bool test=e.modifier();
  if(test)
ui->tv_gestions->setModel(s.afficher());//refresh

}

void Admin::on_tabarticles_22_activated(const QModelIndex &index)
{
    QString val=ui->tabarticles_22->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from tabarticles where NUMERO='"+val+"'");
    if (qry.exec( ))
    {
                  while(qry.next())
                    {
                      ui->lineEdit_numeo->setText(qry.value(0).toString());
                      ui->lineEdit_type->setText(qry.value(1).toString());
                      ui->lineEdit_quantites->setText(qry.value(2).toString());
                      ui->lineEdit_date_expiration->setDateTime(qry.value(3).toDateTime());


                    }
                }

}

void Admin::on_modidier_article_clicked()
{
    int numero= ui->lineEdit_numeo->text().toInt();
    int quantites= ui->lineEdit_quantites->text().toInt();
    QString type= ui->lineEdit_type->text();
   QDateTime date_expiration= ui->lineEdit_date_expiration->dateTime();


     articles a(numero,type,quantites,date_expiration);

 // bool test=a.modifier();
  bool test=a.modifier2();
  if(test)
ui->tabarticles_22->setModel(tmparticles.afficher("select * from tabarticles"));//refresh
}

void Admin::on_modifier_evenement_clicked()
{
    QString typee= ui->lineEdit_type_5->text();
    QString saison= ui->lineEdit_saison_3->text();
    QDateTime date_debut= ui->lineEdit_date_debut_3->dateTime();
    QDateTime date_fin= ui->lineEdit_date_fin_3->dateTime();


     evenement e(typee,saison,date_debut,date_fin);

 // bool test=a.modifier();
  bool test=e.modifier2();
  if(test)
ui->tabevenements->setModel(tmpevenements.afficher("select * from tabevenements"));//refresh
}

void Admin::on_tabevenements_activated(const QModelIndex &index)
{
    QString val=ui->tabevenements->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from tabevenements where TYPEE='"+val+"'");
    if (qry.exec( ))
    {
                  while(qry.next())
                    {
                      ui->lineEdit_type_5->setText(qry.value(0).toString());
                      ui->lineEdit_saison_3->setText(qry.value(1).toString());
                      ui->lineEdit_date_debut_3->setDateTime(qry.value(3).toDateTime());
                      ui->lineEdit_date_fin_3->setDateTime(qry.value(3).toDateTime());
                    }
                }
}
void Admin::on_ajouterr_clicked()
{
    QString nom= ui->lineEdit_Nom->text();
    QString prenom= ui->lineEdit_Prenom->text();
     int id = ui->lineEdit_ID->text().toInt();
  fournisseurs four (nom,prenom,id);
  bool test=four.ajouter();
  if(test)
{ui->tabfour->setModel(four.afficher());//refresh
  }

}

void Admin::on_pushButton_2_clicked()
{


       fournisseurs four;
        ui->tabfour->setModel(four.tri());


}


void Admin::on_lineEdit_2_textChanged(const QString & arg1)
{
    fournisseurs four;
    QString nom=ui->lineEdit_2->text();

    ui->tabfour->setModel(four.rechercher(nom));


}






void Admin::on_pushButton_7_clicked()
{

        QString cat= ui->lineEdit_5->text();
        QString marque= ui->lineEdit_6->text();
         int iden= ui->lineEdit_4->text().toInt();
          QString type= ui->lineEdit_7->text();
      stock s (iden,cat,marque,type);
      bool test=s.ajouters();
      if(test)
    {ui->tabs->setModel(st.affichers());//refresh
      }


}

void Admin::on_pushButton_8_clicked()
{
    int iden = ui->lineEdit_8->text().toInt();
    bool test=st.supprimers(iden);
    if(test)
    {ui->tabs->setModel(st.affichers());//refresh
    }


}

 void Admin::on_pushButton_4_clicked()
{
     ui->tabs->setModel(st.tris());

}


void Admin::on_search_textChanged( const QString & arg1)
{
    QString cat=ui->search->text();
        ui->tabs->setModel(st.recherchers(cat));


}

void Admin::on_pushButton_5_clicked()
{
    stock s;
       int iden=ui->lineEdit_mi->text().toInt();
       QString val=ui->lineEdit_n->text();
       QRegExp rx("[A-Za-z_]+");//[A-Za-z0-9_]
           QRegExp rx1("[0-9_]+");
           QValidator *validator = new QRegExpValidator(rx, this);
           QValidator *validator2 = new QRegExpValidator(rx1, this);
       if(ui->ri->isChecked())
       {
         s.modifieriden(val,iden);
          ui->lineEdit_n->setValidator(validator2);

       }
       if(ui->rm->isChecked())
      {
        if( s.modifiermarque(val,iden))
          ui->lineEdit_n->setValidator(validator);
       }

       if(ui->rt->isChecked())
       {
        s.modifiertype(val,iden);
         ui->lineEdit_n->setValidator(validator);
       }

       if(ui->rc->isChecked())
       {
         s.modifiercategorie(val,iden);
           ui->lineEdit_n->setValidator(validator);

       }

ui->tabs->setModel(s.affichers());
   }


void Admin::on_ri_clicked()
{
    // ui->radioButton_nom->setChecked(false);
       ui->rt->setChecked(false);
       ui->rc->setChecked(false);
       ui->rm->setChecked(false);


}

void Admin::on_rc_clicked()
{
    ui->rt->setChecked(false);
    ui->ri->setChecked(false);
    ui->rm->setChecked(false);

}

void Admin::on_rm_clicked()
{
    ui->rt->setChecked(false);
    ui->rc->setChecked(false);
    ui->ri->setChecked(false);

}

void Admin::on_rt_clicked()
{
    ui->ri->setChecked(false);
    ui->rc->setChecked(false);
    ui->rm->setChecked(false);

}

/*void Admin::sendMail()
{
    Smtp* smtp = new Smtp("ahmed.gontara@esprit.tn","182JMT0108", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(msg(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("ahmed.gontara@esprit.tn", ui->lineEdit_9->text() , ui->lineEdit_10->text(),ui->textEdit->toPlainText());
}

void Admin::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

*/





void Admin::on_pushButton_6_clicked()
{

        int id = ui->lineEdit_id_3->text().toInt();
        bool test=four.supprimer(id);
        if(test)
        {ui->tabfour->setModel(four.afficher());//refresh
         }
    }



void Admin::on_pushButton_20_clicked()
{

    fournisseurs four;
       int id=ui->lineEdit_mi_4->text().toInt();
       QString val=ui->lineEdit_n_4->text();
       if(ui->ri_4->isChecked())
{
         four.modifierid(val,id);
}

       if(ui->rc_4->isChecked())
     {
         four.modifiernom(val,id);
      }

       if(ui->rm_4->isChecked())
       {
        four.modifierprenom(val,id);
       }

 ui->tabfour->setModel(four.afficher());

}




void Admin::on_ri_4_clicked()
{
    // ui->radioButton_nom->setChecked(false);

       ui->rc_4->setChecked(false);
       ui->rm_4->setChecked(false);
}

void Admin::on_rc_4_clicked()
{
    ui->ri_4->setChecked(false);
    ui->rm_4->setChecked(false);

}

void Admin::on_rm_4_clicked()
{
    ui->rc_4->setChecked(false);
    ui->ri_4->setChecked(false);

}

void Admin::on_Affecter_Rayon_clicked()
{
    int num=ui->numAffecter_R->text().toInt();
    QString res=ui->ResAffecter_R->text();

    if(r.affecterResR(num,res))
         {
             popUp->setPopupText("Responsable affecté");
             popUp->show();

         }
         else
{popUp->setPopupText("Responsable n'est pas affecté");
             popUp->show();}
    ui->TableCaisse->setModel(c.afficher());
    ui->TableAffecter_R->setModel(r.afficherVideRay());
    ui->TableLiberer_R->setModel(r.afficherReserveRay());
}

void Admin::on_Liberer_Rayon_clicked()
{
    int num=ui->numLiberer_R->text().toInt();

    if(c.LibererCaisse(num))
         {
             popUp->setPopupText("Caisse libéré");
             popUp->show();

         }
         else
    {popUp->setPopupText("Caisse n'est pas libéré");
    popUp->show();}

    ui->TableCaisse->setModel(r.afficher());
    ui->TableAffecter_R->setModel(r.afficherVideRay());
    ui->TableLiberer_R->setModel(r.afficherReserveRay());
}

void Admin::on_ModifierC_clicked()
{
    int numrech=ui->numAfficherC->text().toInt();
    int num=ui->numAjouter->text().toInt();
    QString Res=ui->ResAjouter->text();
    double CInit=ui->CInitAjouter->text().toDouble();
    int etat;
    if(ui->EtatVideAjouter->isChecked())
        etat=0;
    else etat=1;

    if(c.modifier(num,etat,Res,CInit,numrech))
         {
             QMessageBox::information(nullptr, QObject::tr("Modifier une caisse"),
                         QObject::tr("Caisse Modifié"), QMessageBox::Ok );

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier une caisse"),
                         QObject::tr("Caisse n'est pas modifié"), QMessageBox::Close);

    ui->TableCaisse->setModel(c.afficher());
    ui->TableAffecter->setModel(c.afficherVide());
    ui->TableLiberer->setModel(c.afficherReserve());
}

void Admin::on_ModifierR_clicked()
{
    int numrech=ui->numAfficherR->text().toInt();
    int num=ui->numAjouter_Ray->text().toInt();
    QString type=ui->TypeAjouter_Ray->currentText();
    int etat;
    if(ui->EtatVideAjouter_Ray->isChecked())
        etat=0;
    else etat=1;
    QString res=ui->ResAjouter_Ray->text();

    if(r.modifier(num,type,etat,res,numrech))
             QMessageBox::information(nullptr, QObject::tr("Modifier un rayon"),
                         QObject::tr("Rayon Modifié"), QMessageBox::Ok );
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier un rayon"),
                         QObject::tr("Rayon n'est pas Modifié"), QMessageBox::Close);

    ui->TableRayon->setModel(r.afficher());
    ui->TableAffecter_R->setModel(r.afficherVideRay());
    ui->TableLiberer_R->setModel(r.afficherReserveRay());
}

void Admin::stat()
{
    // prepare data:
    QVector<double> x1(20), y1(20);
    for (int i=0; i<x1.size(); ++i)
    {
      x1[i] = i/(double)(x1.size()-1)*10;
      y1[i] = qCos(x1[i]*0.8+qSin(x1[i]*0.16+1.0))*qSin(x1[i]*0.54)+1.4;
    }
    // create and configure plottables:
    QCPGraph *graph1 = ui->customPlot->addGraph();
    graph1->setData(x1, y1);
    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graph1->setPen(QPen(QColor(120, 120, 120), 2));


    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    graph1->setLayer("abovemain");
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->rescaleAxes();
    ui->customPlot->yAxis->setRange(0, 2);
}

void Admin::on_ActiveCam_clicked()
{
    cam->start();
}

void Admin::on_CaptureCam_clicked()
{
    auto filename = QFileDialog::getSaveFileName(this,"CaptureRayon","/","Image(*.jpg;*.jpeg)");
    if (filename.isEmpty()) {return ;}
    imgcam->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    QImageEncoderSettings imgencset;
    imgencset.setCodec("image/jpeg");
    imgencset.setResolution(1200,800);
    imgcam->setEncodingSettings(imgencset);
    cam->setCaptureMode(QCamera::CaptureStillImage);
    cam->start();
    cam->searchAndLock();
    imgcam->capture(filename);
    cam->unlock();
    QMessageBox::information(nullptr, QObject::tr("Capturer une image"),
                             QObject::tr("Image capturé"), QMessageBox::Ok );
}

void Admin::on_DesactiveCam_clicked()
{
    cam->stop();
}

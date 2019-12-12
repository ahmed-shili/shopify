#ifndef ADMIN_H
#define ADMIN_H
#include <QMainWindow>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QApplication>
#include <QMessageBox>
#include "caisse.h"
#include "rayon.h"
#include "salaries.h"
#include "articles.h"
#include "evenement.h"
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include"client.h"
#include"cadeaux.h"
#include <QMainWindow>
#include "smtp.h"
#include "cmdvente.h"
#include "cmdachat.h"
#include "conges.h"
#include<QDateTime>
#include "popup.h"
#include "fournisseurs.h"
#include "stock.h"

#include <QTimer>
#include "qcustomplot.h"
#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>
#include <QVBoxLayout>

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void stat();
    void sendMail();
    void mailSent(QString);
    void sendMail1();
    void mailSent1(QString);
    void on_AjouterC_clicked();

    void on_AjouterR_clicked();

    void on_numAfficherC_textChanged(const QString &arg1);

    void on_TriC_currentIndexChanged(int index);

    void on_numAfficher_R_textChanged(const QString &arg1);

    void on_Tri_R_currentIndexChanged(int index);

    void on_EtatVideAjouter_Ray_clicked();

    void on_EtatGuarAjouter_Ray_clicked();

    void on_EtatVideAjouter_clicked();

    void on_EtatResAjouter_clicked();

    void on_Affecter_clicked();

    void on_Liberer_clicked();

    void on_SupprimerC_clicked();

    void on_SupprimerR_clicked();

    void on_numAfficherR_textChanged(const QString &arg1);

    void on_AjouterSTW_clicked();

    void on_IDAfficherS_textChanged(const QString &arg1);

    void on_SupprimerSTW_clicked();

    void on_Le_idconges_textChanged(const QString &arg1);

    void on_calculersalaire_clicked();

    int on_fichedepaie_clicked();

    void on_ajouter_articles_clicked();


    void on_supprimer_articles_clicked();

    void on_numero_sup_rech_mod_textChanged(const QString &arg1);

    void on_ajout_evenement_clicked();

    void on_type_supp_rech_mod_textChanged(const QString &arg1);

    void on_supprimer_eve_clicked();

    void on_pb_affecter_clicked();

    void on_supprimer_evenement_clicked();

    void on_pushButton_4_ajouterclient_clicked();



    void on_supprimeclient_clicked();

    void on_pushButton_trier_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_cadeauajouter_clicked();

    void on_supprimer_cadeau_clicked();

    void on_comboBox_2_activated(const QString &arg1);



    void on_lineEdit_rechcad_textChanged(const QString &arg1);

    void on_lineEdit_recher_cad_textChanged(const QString &arg1);

    void on_tabetudiant_activated(const QModelIndex &index);



    void on_modifier_client_clicked();

    void on_tableView_cad_activated(const QModelIndex &index);



    void on_modif_cad_clicked();

    void on_trie_client_currentIndexChanged(const QString &arg1);
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_pb_trier_clicked() ;
    void on_pb_statistique_clicked() ;
    void on_pb_ajouter1_clicked();
void on_lineEdit_6_textChanged(const QString  &arg1);
    void on_pb_supprimer1_clicked();
    void on_pb_modifier1_clicked();
void on_lineEdit_9_textChanged(const QString  &arg2);

void on_ConfirmerS_clicked();

void on_TriA_2_currentIndexChanged(int index);

void on_TriA_currentIndexChanged(int index);

void on_tv_gestions_activated(const QModelIndex &index);

void on_ModiferSTW_clicked();

void on_tabarticles_22_activated(const QModelIndex &index);

void on_modidier_article_clicked();

void on_modifier_evenement_clicked();

void on_tabevenements_activated(const QModelIndex &index);
void on_ajouterr_clicked();


void on_pushButton_2_clicked();



void on_lineEdit_2_textChanged(const QString & arg1);


void on_pushButton_7_clicked();

void on_pushButton_8_clicked();

void on_pushButton_4_clicked();

void on_search_textChanged(const QString &arg1);

void on_pushButton_5_clicked();

void on_ri_clicked();

void on_rc_clicked();

void on_rm_clicked();

void on_rt_clicked();

void on_pushButton_6_clicked();



void on_pushButton_20_clicked();

void on_ri_4_clicked();

void on_rc_4_clicked();

void on_rm_4_clicked();

void on_Affecter_Rayon_clicked();

void on_Liberer_Rayon_clicked();

void on_ModifierC_clicked();

void on_ModifierR_clicked();

void on_ActiveCam_clicked();

void on_CaptureCam_clicked();

void on_DesactiveCam_clicked();

private:
    Ui::Admin *ui;
    Caisse c;
    Rayon r;
    salaries s;
    cmdvente e ;
    articles tmparticles;
    evenement tmpevenements;
     client tmpclient;
     cadeaux tmpcad;
     cmdvente tmp;
      cmdachat tmp1;
      conges co;
      PopUp *popUp;
      fournisseurs four;
      stock st;

      QCamera *cam;
      QCameraImageCapture *imgcam;
      QCameraViewfinder *camview;
      QVBoxLayout *camlayout;
};

#endif // ADMIN_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QApplication>
#include <QMessageBox>
#include "admin.h"
#include "employes.h"
#include "articles.h"
#include "evenement.h"
#include <QDebug>
#include "arduino.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Login_clicked();
    void update_label();

private:
    Ui::MainWindow *ui;
    Admin *admin;
    employes *Employes;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire

};

#endif // MAINWINDOW_H

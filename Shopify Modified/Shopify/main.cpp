#include "mainwindow.h"
#include "connection.h"
#include "admin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connexion c;

  if(c.ouvrirConnexion())
  {
    w.show();

    QMessageBox::information(nullptr, QObject::tr("database is not open"),
                QObject::tr("connection avec succés.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("connection failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/image/resource/background.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
        int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update_label()
{
    QString data=A.read_from_arduino();
      qDebug() <<data;
    if(data=="57139140187\r\n")
{

        ui->user->setText("admin"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON
         ui->pass->setText("test");
         A.write_to_arduino("x");


}
    else if (data.contains(',')){ data="";}
        else {
        ui->user->setText("denied"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON
         ui->pass->setText("denied");
       A.write_to_arduino("y");
        // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
    }
}
void MainWindow::on_Login_clicked()
{
    QString username = ui->user->text();
    QString password = ui->pass->text();

    if(username == "admin" && password == "test") {
        QMessageBox::information(this, "Login", "Logging in");
        hide();
        admin = new Admin(this);
        admin->show();
        A.write_to_arduino("x");
    }
       else if(username == "salaries" && password == "test") {
            QMessageBox::information(this, "Login", "Logging in");
            this->hide();
            Employes = new employes(this);
            Employes->show();
A.write_to_arduino("y");

    }
    else {
        QMessageBox::warning(this,"Login","wrong password or username");
    }
}

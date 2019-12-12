#include "statistique.h"
#include "ui_statistique.h"
#include "nightchart.h"
statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}
void statistique :: paintEvent(QPaintEvent *){

    int h=e.stat_nbr_commande();
    int p=e.stat_nbr_commande1();
    int E=e.stat_nbr_commande2();
    int a=e.stat_nbr_commande3();

    int m=a+E+p+h;
    int teta= (a*100)/m;
    int teta2=(E*100)/m;
    int teta3=(p*100)/m;
    int teta4=100-(teta+teta2+teta3);

    QPainter painter(this);
    QFont font;
    painter.begin(this);
    Nightcharts PieChart;
    PieChart.setType(Nightcharts::Dpie);
    PieChart.setLegendType(Nightcharts::Vertical);
    PieChart.setCords(50,50,this->width()/1.5,this->height()/1.5);
    PieChart.addPiece("Hiver",Qt::red,teta);
    PieChart.addPiece("Ete",Qt::green,teta2);
    PieChart.addPiece("Automne",Qt::gray,teta3);
    PieChart.addPiece("Hiver",Qt::cyan,teta4);
    PieChart.draw(&painter);
    PieChart.drawLegend(&painter);

}



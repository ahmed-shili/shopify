#ifndef NIGHTCHARTS_H
#define NIGHTCHARTS_H
#define PerConst = 3.6;
#include <QObject>
#include <QPainter>
#include <QVector>
#include <QDebug>
#include <QLinearGradient>
#include <math.h>

class pieceNC
{
public:
    explicit pieceNC();
    void addName(QString name);
    void setColor(Qt::GlobalColor);
    void setColor(QColor color);
    void setPerc(float Percentage);

    QString pname;
    QColor rgbColor;
    float pPerc;

private:

};

class Nightcharts
{
public:

    explicit Nightcharts();
    ~Nightcharts();
    enum type { Histogramm , Pie, Dpie };
    enum legend_type{ /*Horizontal,*/ Vertical, Round };
    int addPiece(QString name,Qt::GlobalColor,float Percentage);
    int addPiece(QString name,QColor, float Percentage);
    int setCords(double x, double y, double w, double h);
    int setLegendCords(double x, double y);
    int setType(Nightcharts::type t);
    int setLegendType(Nightcharts::legend_type t);
    int setShadows(bool ok = true);
    int setFont(QFont f);
    int draw(QPainter *painter);
    int drawLegend(QPainter *painter);
    double palpha;

private:
    double cX,cY,cW,cH,pW,lX,lY;
    int nPiece;
    bool shadows;
    QVector<pieceNC> pieces;
    int ctype, cltype;
    QFont font;
    //QPainter *cpainter;
    QPointF GetPoint(double angle, double R1 = 0, double R2 = 0);
    int GetQuater(double angle);
    double Angle360(double angle);


signals:

public slots:

};


#endif // NIGHTCHARTS_H

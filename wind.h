#ifndef WIND_H
#define WIND_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

class Wind{
public:
    Wind();


    void setPainter();
    void generateWind();
    void setArrow();
    void resetArrow();
    int speed;
    double angle;
    double reset_angle;
    QPolygon arrow;
    QMatrix matrix;
    QBrush fillbrush;
    QPen pen;
    QColor color;
};

#endif // WIND_H

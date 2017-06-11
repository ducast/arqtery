#ifndef TANK_H
#define TANK_H

#include <QApplication>
#include <QDialog>
#include <QtGui>
#include <QtCore>

#include"bullet.h"


class Tank{
public:
    Tank();

    void setPainter();
    bool bulletHit(Bullet bullet);
    QBrush fillbrush;
    QPen pen;
    QRect shape;
    QColor color;

};







#endif // TANK_H

#ifndef CANNON_H
#define CANNON_H

#include "bullet.h"

#include <QApplication>
#include <QDialog>
#include <QtGui>
#include <QtCore>


class Cannon{
public:
    Cannon();

    void setPainter();
    QBrush fillbrush;
    QPen pen;
    QRect shape;
    QColor color;
    bool invert;
    int speed;
    int x1;
    int y1;
    int x2;
    int y2;
    int id;
    double angle;


};

#endif // CANNON_H

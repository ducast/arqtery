#ifndef BULLET_H
#define BULLET_H

#include "cannon.h"

#include <QApplication>
#include <QDialog>
#include <QtGui>
#include <QtCore>

class Cannon;

class Bullet{
public:
    Bullet();

    int x_pos;
    int y_pos;
    int speed;
    int radius;
    double time;
    double angle;
    void calcPos(int wind_speed, double wind_angle);
    void collision(Cannon cannon);
    void shoot(Cannon cannon);
    void setPainter();
    bool invert;
    QColor color;
    QPen pen;
};
#endif // BULLET_H

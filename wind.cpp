#include "wind.h"
#include <math.h>
#include <QApplication>

#include<iostream>
using namespace std;

Wind::Wind()
{
    this->speed = rand()%25;
    this->angle = rand()%100 / 50 * M_PI;
    this->color = Qt::black;
    this->arrow << QPoint(700, 60);
    this->arrow << QPoint(670, 63);
    this->arrow << QPoint(670, 57);

}

void Wind::generateWind(){
    if ((rand()%12)%3 == 0){
        this->speed = rand()%25;
        this->angle = rand()%100 / 50.0 * M_PI;
    }
    setArrow();
}
void Wind::setArrow(){
    this->resetArrow();
    QTransform t;
    t.translate(670,60);
    t.rotateRadians(-this->angle);
    t.translate(-670,-60);
    this->arrow = t.map(this->arrow);
    this->reset_angle = angle;
}

void Wind::resetArrow(){
    QTransform t;
    t.translate(670,60);
    t.rotateRadians(this->reset_angle);
    t.translate(-670,-60);
    this->arrow = t.map(this->arrow);
}

void Wind::setPainter (){

    this->fillbrush.setColor(this->color);
    this->fillbrush.setStyle(Qt::SolidPattern);

    this->pen.setWidth(1);
    this->pen.setColor(this->color);
    this->pen.setBrush(fillbrush);
}


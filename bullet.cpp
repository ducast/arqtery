#include "bullet.h"

#include <math.h>

#include<iostream>
using namespace std;

Bullet::Bullet()
{
}


//class Cannon;

void Bullet::calcPos(int wind_speed, double wind_angle){

    int gravity = 10;

    double angle = this->angle;

    if (this->invert)
        this->x_pos -= this->speed*cos(angle)*this->time;
    else
        this->x_pos += this->speed*cos(angle)*this->time;

    //GRAVITY
    this->y_pos -= this->speed*sin(angle)*this->time - gravity*this->time*this->time/2;

    //WIND
    this->x_pos += wind_speed*cos(wind_angle)*this->time;
    this->y_pos -= wind_speed*sin(wind_angle)*this->time;


}

void Bullet::setPainter(){
    this->pen.setWidth(5);
    this->pen.setColor(this->color);
}

void Bullet::shoot(Cannon cannon){

    this->x_pos = cannon.x2;
    this->y_pos = cannon.y2;
    this->speed = cannon.speed;
    this->invert = cannon.invert;
    this->radius = 15;
}

#include "tank.h"

Tank::Tank()
{
}

void Tank::setPainter (){

    this->fillbrush.setColor(this->color);
    this->fillbrush.setStyle(Qt::SolidPattern);

    this->pen.setWidth(1);
    this->pen.setColor(this->color);
    this->pen.setBrush(fillbrush);
}

bool Tank::bulletHit(Bullet bullet){
    return this->shape.contains(bullet.x_pos, bullet.y_pos);
}

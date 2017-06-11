#include "cannon.h"


#include <iostream>
using namespace std;

Cannon::Cannon()
{
}

void Cannon::setPainter(){

    this->fillbrush.setColor(this->color);
    this->fillbrush.setStyle(Qt::SolidPattern);

    this->pen.setWidth(5);
    this->pen.setColor(this->color);
    this->pen.setBrush(fillbrush);

}

#include "field.h"
#include <iostream>
using namespace std;
Field::Field()
{
    this->color = Qt::green;
}

void Field::generateField(){


    this->canvas_w = 800;
    this->canvas_h = 600;

    QPolygon poly;
    poly << QPoint(canvas_w, canvas_h);
    poly << QPoint(0, canvas_h);

    this->initial_h = (90-rand()%10)/100.0 * canvas_h;
    int field_h = initial_h;
    int max_h = 0.1*canvas_h;
    int min_h = 0.9*canvas_h;
    for(int field_w = 0; field_w <= canvas_w; field_w+=1){
        poly << QPoint(field_w, field_h);
        if (field_w < 100 || field_w > 700){
            field_h = field_h;
        }
        else{
            int n = rand()%(1+rand()%5);
            for (int i = 0; i < n; i++){
                if ((field_w < canvas_w/2 && field_h > max_h) || field_h > min_h)
                    field_h -= 1;
                else
                    field_h += 1;
                poly << QPoint(field_w, field_h);
            }
        }
        this->final_h = field_h;
    };
    poly << QPoint(canvas_w, canvas_h);

    this->shape = poly;

}

void Field::setPainter(){

    this->fillbrush.setColor(this->color);
    this->fillbrush.setStyle(Qt::SolidPattern);
    this->pen.setStyle(Qt::DotLine);
    this->pen.setWidth(1);
    this->pen.setColor(this->color);
    this->pen.setBrush(fillbrush);


}

bool Field::bulletHit(Bullet bullet){
    QPoint point(bullet.x_pos, bullet.y_pos);
    return shape.containsPoint(point, Qt::OddEvenFill);
}

void Field::deformField(Bullet bullet){

    int x = bullet.x_pos;
    int y = bullet.y_pos;
    int radius = bullet.radius;
    int new_x = 0;
    int new_y = 0;


    QPolygon circle;
    for (double i=M_PI/2; i<M_PI*5/2; i+= 0.01){
        new_x = x + cos(i)*radius;
        new_y = y + sin(i)*radius;
        QPoint point = QPoint(new_x, new_y);
        if (!circle.containsPoint(point,Qt::OddEvenFill))
            circle << QPoint(new_x, new_y);

    }

    this->shape = this->shape.subtracted(circle);
}




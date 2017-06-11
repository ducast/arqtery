#ifndef FIELD_H
#define FIELD_H

#include <QApplication>
#include <QDialog>
#include <QtGui>
#include <QtCore>

#include"bullet.h"

class Field{

public:
    Field();

    void generateField();
    void setPainter();
    void deformField(Bullet bullet);
    int canvas_w;
    int canvas_h;
    int initial_h;
    int final_h;
    bool bulletHit(Bullet bullet);
    QPolygon shape;
    QColor color;
    QBrush fillbrush;
    QPen pen;



};


#endif // FIELD_H

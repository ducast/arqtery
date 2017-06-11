#ifndef DIALOG_H
#define DIALOG_H

#include "field.h"
#include "tank.h"
#include "cannon.h"
#include "bullet.h"
#include "wind.h"

#include <QMessageBox>
#include <QTimer>
#include <QDialog>
#include <QtGui>
#include <QtCore>
#include<iostream>
using namespace std;


class Field;
class Tank;
class Cannon;
class Bullet;
class Wind;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void uiSetup();
    void restartApp();

    Field field;
    Tank tank1;
    Tank tank2;
    Cannon cannon1;
    Cannon cannon2;
    Cannon cannonx;
    Bullet bullet;
    Wind wind;


private slots:
    void on_pushButton_Fire_clicked();


    void on_pushButton_decreaseAngle_clicked();

    void on_pushButton_increaseAngle_clicked();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

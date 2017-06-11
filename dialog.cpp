#include "dialog.h"
#include "ui_dialog.h"
#include "math.h"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{


    //Set Game
   Dialog::uiSetup();
   // SET First Player
   cannonx = cannon1;


}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::paintEvent(QPaintEvent *){

    //Mostrar Wind

    ui->lcdNumber->display(wind.speed*4);

   // Set Shooting Cannon

    bullet.shoot(cannonx);
    QPainter painter(this);

    //PAINT FIELD
    QPainterPath field_path;
    field_path.addPolygon(field.shape);
    field.setPainter();
    painter.setPen(field.pen);
    painter.drawPolygon(field.shape);
    painter.fillPath(field_path, field.fillbrush);

    //PAINT WIND
    QPainterPath wind_path;
    wind_path.addPolygon(wind.arrow);
    wind.setPainter();
    painter.setPen(wind.pen);
    painter.drawPolygon(wind.arrow);
    painter.fillPath(wind_path, wind.fillbrush);

    //PAINT TANK1
    tank1.setPainter();
    painter.setPen(tank1.pen);
    painter.drawRect(tank1.shape);
    painter.fillRect(tank1.shape, tank1.fillbrush);

    //PAINT TANK2
    tank2.setPainter();
    painter.setPen(tank2.pen);
    painter.drawRect(tank2.shape);
    painter.fillRect(tank2.shape, tank2.fillbrush);

    //CHANGLE CANNON ANGLE
    if (cannonx.id == cannon1.id){
        cannon1.x2 = cannon1.x1 +( 20 * cos(cannonx.angle));
        cannon1.y2 = cannon1.y1 + (20 * sin(cannonx.angle));
        cannon1.speed = 20+ (ui->lcdNumber_power->intValue())* 120 / 100 ;
        bullet.shoot(cannon1);
    }
    if (cannonx.id == cannon2.id){
        cannon2.x2 = cannon2.x1 + ( 20 * cos(cannonx.angle));
        cannon2.y2 = cannon2.y1 + (20 * sin(cannonx.angle));
        cannon2.speed = 20 + (ui->lcdNumber_power->intValue())* 120 / 100 ;
        bullet.shoot(cannon2);
    }

    //PAINT CANNON1
    cannon1.setPainter();
    painter.setPen(cannon1.pen);
    painter.drawLine(cannon1.x1,cannon1.y1,cannon1.x2,cannon1.y2);

    //PAINT CANNON2
    cannon2.setPainter();
    painter.setPen(cannon2.pen);
    painter.drawLine(cannon2.x1,cannon2.y1,cannon2.x2,cannon2.y2);

    update();

    //PAINT BULLET
    if (cannonx.invert) bullet.angle = M_PI+cannonx.angle;
    else bullet.angle = -cannonx.angle;
    bullet.calcPos(wind.speed, wind.angle);
    bullet.setPainter();
    painter.setPen(bullet.pen);
    painter.drawPoint(bullet.x_pos,bullet.y_pos);

};

void Dialog::keyPressEvent(QKeyEvent *e){
    if (e->key()==Qt::Key_Up){
        if (cannonx.invert)
            on_pushButton_increaseAngle_clicked();
        else
            on_pushButton_decreaseAngle_clicked();
    }

    if (e->key()==Qt::Key_Down){
        if (!cannonx.invert)
            on_pushButton_increaseAngle_clicked();
        else
            on_pushButton_decreaseAngle_clicked();
    }

    if (e->key()==Qt::Key_Left){
        int value = ui->horizontalSlider->value();
        value --;
        ui->horizontalSlider->setValue(value);
        repaint();
    }

    if (e->key()==Qt::Key_Right){
        int value = ui->horizontalSlider->value();
        value ++;
        ui->horizontalSlider->setValue(value);
        repaint();
    }

    if (e->key()==Qt::Key_Space)
        on_pushButton_Fire_clicked();

}

void Dialog::on_pushButton_Fire_clicked()
{
  // RePaint Loop
    while (bullet.x_pos > -5 && bullet.x_pos < field.canvas_w +5 ){

        bullet.time += 0.02;


        if (tank1.bulletHit(bullet)){

            QMessageBox::information(this,tr("GAME OVER"),tr("Player 2 Wins"));
            QProcess::startDetached(QApplication::applicationFilePath());
            exit(12);
            break;

        }

        if (tank2.bulletHit(bullet)){

            QMessageBox::information(this,tr("GAME OVER"),tr("Player 1 Wins"));
            QProcess::startDetached(QApplication::applicationFilePath());
            exit(12);
            break;
        }

        if (field.bulletHit(bullet)){
            field.deformField(bullet);
            update();
            break;
        }

        QThread::msleep(1);
        repaint();

    }

    if (cannonx.invert) {
        cannonx = cannon1;
        ui->label->setText("Blue Player's Turn");
    }
    else{

        cannonx = cannon2;
        ui->label->setText("Red Player's Turn");
    // Reset Bullet position
    }
    bullet.time = 0;
    wind.generateWind();




}




void Dialog::on_pushButton_decreaseAngle_clicked()
{
    if (cannonx.invert){
        cannonx.angle -= 0.03;
        cannon2.angle -= 0.03;
    }
    else{
        cannonx.angle -= 0.03;
        cannon1.angle -= 0.03;
    }

    QThread::msleep(10);
    repaint();
}

void Dialog::on_pushButton_increaseAngle_clicked()
{
    if (cannonx.invert){
        cannonx.angle += 0.03;
        cannon2.angle += 0.03;
    }
    else{
        cannonx.angle += 0.03;
        cannon1.angle += 0.03;
    }

    QThread::msleep(10);
    repaint();

}



void Dialog::uiSetup()
{

    ui->setupUi(this);

    //FIELD
    field.generateField();
    field.color = Qt::green;

    wind.generateWind();

    //TANKS
    tank1.color = Qt::blue;
    int rect1_w = field.canvas_w/15;
    int rect1_h = field.initial_h-20;
    tank1.shape.setRect(rect1_w,rect1_h,40,20);

    tank2.color = Qt::red;
    int rect2_w = field.canvas_w*14/15;
    int rect2_h = field.final_h-20;
    tank2.shape.setRect(rect2_w,rect2_h,-40,20);


    // SET First Player
    cannonx = cannon1;

    //CANNONS
    cannon1.color = Qt::black;
    cannon1.angle = -M_PI/3; // cannon.angle (needs to be equal in bullet.cpp and vary by user command)
    cannon1.x1 = rect1_w+20 ;
    cannon1.y1 = field.initial_h - 15;
    cannon1.x2 = cannon1.x1 +( 20 * cos(cannon1.angle)) ;
    cannon1.y2 = field.initial_h - 15 + (20 * sin(cannon1.angle));
    cannon1.id = 1;
    cannon1.speed = 120;
    cannon1.invert = false;

    cannon2.color = Qt::black;
    cannon2.angle = -2*M_PI/3; // cannon.angle (needs to be equal in bullet.cpp and vary by user command)
    cannon2.x1 = rect2_w-20;
    cannon2.y1 = field.final_h - 15 ;
    cannon2.x2 = cannon2.x1 + ( 20 * cos(cannon2.angle));
    cannon2.y2 = cannon2.y1 + (20 * sin(cannon2.angle));
    cannon1.id = 2;
    cannon2.speed = 120;
    cannon2.invert = true;

    // BULLET
    bullet.x_pos = cannonx.x2;
    bullet.y_pos = cannonx.y2;


}

void Dialog::restartApp()
{

    Dialog::uiSetup();

    repaint();
}

void Dialog::on_pushButton_clicked()
{
           exit(12);
}

void Dialog::on_pushButton_2_clicked()
{
    QProcess::startDetached(QApplication::applicationFilePath());
    exit(12);
}

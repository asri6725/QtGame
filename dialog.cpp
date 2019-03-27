#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include <iostream>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    bg_x(0)

{
    ui->setupUi(this);
    // connect it with a timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunction()));
    timer->start(100);
    this->update();
}

void Dialog::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    // draw background

    QImage image("C:/Users/Abhi/Desktop/bg.png");                   //load image
    image = image.scaledToHeight(500, Qt::FastTransformation);      // set constant height

    int height = image.height();                                    // need frame of reference to draw stickman
    int width = image.width();                                      // ^same and to update frames


    QRectF target(10.0, 20.0, 900, height);
    QRectF source(0.0+bg_x, 0.0, 450, height);

    painter.drawImage(target, image, source);
    std::cout << bg_x <<std::endl;

    // draw stickman

    //make a pen

    QPen linepen;
    linepen.setWidth(4);

    // draw
    int man_x = 30, man_y = height/2;
    painter.setPen(linepen);
    painter.drawEllipse(0+man_x,0+man_y,30,30);
    painter.drawLine(15+man_x,30+man_y,15+man_x,100+man_y);
    painter.drawArc(0+man_x,100+man_y,30, 40, 30*16,120*16);
    painter.drawArc(0+man_x,50+man_y,30, 40, 30*16,120*16);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::myfunction()
{
    bg_x = bg_x+1;
    this->update();
}

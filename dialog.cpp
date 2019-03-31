#include "dialog.h"
#include "ui_dialog.h"

#include <iostream>
#include <QtCore>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    this->readfile();
    this->setValues();
    ui->setupUi(this);
    this->resize(400,200);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(100);

    this->update();
}

void Dialog::readfile()
{
    QString loc = "C:/Users/Abhi/Desktop/config.json";
    read ob;
    ob.setloc(loc);
    this->json = ob.readjson();


}

void Dialog::setValues()
{
    bg.setImg(this->json["background"].toString());
    bg.set_x_speed(this->json["velocity"].toInt());
    man.setSize(this->json["size"].toString());
    man.set_x_pos(this->json["xposition"].toInt());

}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::nextFrame()
{
    bg.move();
    this->update();
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    bg.renderBackImg(painter, this->height());
    man.renderStickman(painter);
}

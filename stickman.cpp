#include "stickman.h"

stickman::stickman()
{
    this->size = "NULL";
}

void stickman::renderStickman(QPainter &painter)
{
    painter.drawEllipse(0+this->get_x_pos(),0+this->get_y_pos(),30,30);
    painter.drawLine(15+this->get_x_pos(),30+this->get_x_pos(),15+this->get_x_pos(),100+this->get_y_pos());
    painter.drawArc(0+this->get_x_pos(),100+this->get_y_pos(),30, 40, 30*16,120*16);
    painter.drawArc(0+this->get_x_pos(),50+this->get_y_pos(),30, 40, 30*16,120*16);
}

void stickman::setSize(QString size)
{
    this->size = size;
}

QString stickman::showSize()
{
    return this->size;
}

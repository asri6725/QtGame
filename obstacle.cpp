#include "obstacle.h"
#include <QRect>
#include <iostream>

Obstacle::Obstacle(Position *pos, QPixmap *sprite, QString type){ this->pos = pos; this->sprite = sprite; this->type = type;}

Obstacle::Obstacle(int x, int y, int w, int h, QPixmap *sprite, QString type)
{
    this->pos = new Position(x, y, w,h);
    this->sprite = sprite;
    this->type = type;
}

Obstacle::~Obstacle()
{
    delete sprite;
    delete pos;
}

QString Obstacle::obsType()
{
    return this->type;
}

void Obstacle::render(QPainter &painter)
{

    QRect* rect = new QRect(pos->getX(), pos->getY(), pos->getWidth(), pos->getHeight());

    painter.drawPixmap(*rect, *sprite);
}

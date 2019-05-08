#include "obstacle.h"
#include <QRect>
#include <iostream>

obstacle::obstacle(Position *pos, QPixmap *sprite, QString type){ this->pos = pos; this->sprite = sprite; this->type = type;}

obstacle::obstacle(int x, int y, int w, int h, QPixmap *sprite, QString type)
{
    this->pos = new Position(x, y, w,h);
    this->sprite = sprite;
    this->type = type;
}

obstacle::~obstacle()
{
    delete sprite;
    delete pos;
}

QString obstacle::obsType()
{
    return this->type;
}

void obstacle::render(QPainter &painter)
{

    QRect* rect = new QRect(pos->getX(), pos->getY(), pos->getWidth(), pos->getHeight());

    painter.drawPixmap(*rect, *sprite);
}

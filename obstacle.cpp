#include "obstacle.h"
#include <QRect>
#include <iostream>

obstacle::obstacle(Position *pos, QPixmap *sprite){ this->pos = pos; this->sprite = sprite; std::cout << "obstacle constructor" << std::endl;}

obstacle::obstacle(int x, int y, int w, int h, QPixmap *sprite)
{
    this->pos = new Position(x, y, w,h);
    this->sprite = sprite;
}

obstacle::~obstacle()
{
    delete sprite;
    delete pos;
    delete this;
}

void obstacle::render(QPainter &painter)
{

    QRect* rect = new QRect(pos->getX(), pos->getY(), pos->getWidth(), pos->getHeight());

    painter.drawPixmap(*rect, *sprite);
}

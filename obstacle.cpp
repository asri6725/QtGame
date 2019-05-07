#include "obstacle.h"
#include <QRect>
#include <iostream>

obstacle::obstacle(Position *pos, std::string type){ this->pos = pos; this->type = type; }

obstacle::obstacle(int x, int y, int w, int h, std::string type)
{
    this->pos = new Position(x, y, w,h);
    this->type = type;
}

obstacle::~obstacle()
{
    delete pos;
    delete this;
}

void obstacle::render(QPainter &painter)
{

    QRect* rect = new QRect(pos->getX(), pos->getY(), pos->getWidth(), pos->getHeight());
    QBrush brush;
    brush.color(this->type);
    painter.setBrush(brush);

    painter.drawRect(*rect);
}

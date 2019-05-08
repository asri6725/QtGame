#include "obstacle.h"

//constructor
Obstacle::Obstacle(Position *pos, QPixmap *sprite, QString type){
    this->pos = pos; this->sprite = sprite;
    this->type = type;
}

//constructor
Obstacle::Obstacle(int x, int y, int w, int h, QPixmap *sprite, QString type)
{
    this->pos = new Position(x, y, w,h);
    this->sprite = sprite;
    this->type = type;
}

//destructor
Obstacle::~Obstacle()
{
    delete sprite;
    delete pos;
}

//returns the obstacle type
QString Obstacle::obsType()
{
    return this->type;
}

//render obstacle
void Obstacle::render(QPainter &painter)
{

    QRect* rect = new QRect(pos->getX(), pos->getY(), pos->getWidth(), pos->getHeight());

    painter.drawPixmap(*rect, *sprite);
}

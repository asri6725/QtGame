#include "worldobject.h"

// Constructors + Destructors
WorldObject::WorldObject(Position *pos, QPixmap *sprite): pos(pos), sprite(sprite){}
WorldObject::~WorldObject(){
    delete pos;
}

// Render method
void WorldObject::render(QPainter& painter){
    painter.drawPixmap(pos->getX(), pos->getY(), pos->getWidth(), pos->getHeight(), *sprite);
}

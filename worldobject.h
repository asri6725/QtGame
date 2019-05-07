#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <string>
#include <QPixmap>
#include <QPainter>
#include "position.h"

class WorldObject {

public:

    // Constructors + Destructors + type
    WorldObject(Position* pos, QPixmap* sprite);
    virtual ~WorldObject();
    virtual std::string type() = 0;

    // Update / draw
    void render(QPainter& painter);
    virtual void updatePosition(int xChange) = 0;

protected:

    // Attributes
    Position* pos;
    QPixmap* sprite;

};

#endif // WORLDOBJECT_H

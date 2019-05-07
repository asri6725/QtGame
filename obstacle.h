#ifndef OBSTACLE_H
#define OBSTACLE_H

#include<QPainter>
#include <position.h>
//#include <worldobject.h>
#include <define.h>
#include <QPixmap>
class obstacle
{
public:
    obstacle(Position *pos, QPixmap *sprite);
    obstacle(int x, int y, int w, int h, QPixmap *sprite);
    ~obstacle();

    void render(QPainter &painter);
    Position *pos;
private:
    QPixmap* sprite;
};

#endif // OBSTACLE_H

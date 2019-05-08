#ifndef OBSTACLE_H
#define OBSTACLE_H
// could have used world object, but I ran out of time, will update if i finish early.

#include<QPainter>
#include <position.h>
//#include <worldobject.h>
#include <define.h>
#include <QPixmap>
class obstacle
{
public:
    obstacle(Position *pos, QPixmap *sprite, QString type);                   // use this constructor to just readd an existing obstacle to the end of a list after changing it's xposition
    obstacle(int x, int y, int w, int h, QPixmap *sprite, QString type);      // i use this to create a new obstacle for the first time
    ~obstacle();
    //obstacle tpe
    QString obsType();

    //draw obstacle
    void render(QPainter &painter);
    Position *pos;
private:
    QPixmap* sprite;
    QString type;
};

#endif // OBSTACLE_H

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include<QPainter>
#include <position.h>
//#include <worldobject.h>
#include <define.h>

class obstacle
{
public:
    obstacle(Position *pos, std::string type);
    obstacle(int x, int y, int w, int h, std::string type);
    ~obstacle();

    void render(QPainter &painter);

private:
    std::string type;
};

#endif // OBSTACLE_H

#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "obstacle.h"
#include "moveplayer.h"
#include <QPainter>

class obstacles
{
public:
    obstacles(int number, int speed, moveplayer *p);
    ~obstacles();

    void render(QPainter &painter);

    //check for collision with the player

    bool collision(obstacle *ob);
    //destroy and recreate obstacles
    void helper();

    //set velocity
    void setvelocity(int velval);
    int getvelocity();

private:
    int number, speed;
    std::vector<obstacle *> obstacless;
    moveplayer *p;
};

#endif // OBSTACLES_H

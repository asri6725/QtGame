#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "obstacle.h"
#include "moveplayer.h"
#include "config.h"
#include <QPainter>

class obstacles
{
public:
    obstacles(Config* config, moveplayer *p);
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
    int number, speed, spacing;
    std::vector<obstacle *> obstacless;
    moveplayer *p;
};

#endif // OBSTACLES_H

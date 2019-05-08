#ifndef COLLISION_H
#define COLLISION_H

#include "moveplayer.h"
#include "obstacles.h"
#include "worldmanager.h"
#include "config.h"

class collision
{
public:
    collision(WorldManager *bg, moveplayer *p, obstacles *ob, Config *config, bool extend);
    //checks for collision
    bool iscolliding();
    //basic functions on collision: background and obstacles stop moving, player cannot go through the obstacle.
    void onCollision();

    //additional functions
    //destroys blue obstacles if we jump on them, destroys red obstacles if we jump from below them
    void difficultDestroy();

private:
    moveplayer *p;
    obstacles *obs;
    WorldManager *bg;
    Config *config;
    bool extend;
};

#endif // COLLISION_H

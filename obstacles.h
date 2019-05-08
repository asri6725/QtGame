#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "obstacle.h"
#include "moveplayer.h"
#include "worldmanager.h"
#include "config.h"
#include <QPainter>

class obstacles
{
public:
    //not able to configure this constructor correctly, the intent is to create multiple obstacles with different sizes and y values but it isn't working
    obstacles(Config* config, moveplayer *p, WorldManager *wm);
    ~obstacles();

    void render(QPainter &painter);

    //destroy and recreate obstacles when they go outside the screen
    void updateObs();
    //destroy obstacles
    void destroyObs(obstacle *ob);
    //set velocity
    void setvelocity(int velval);
    int getvelocity();
    std::vector<obstacle *> obstacless;
private:
    int number, speed, spacing;
    moveplayer *p;
    WorldManager *wm;
    Config *config;
};

#endif // OBSTACLES_H

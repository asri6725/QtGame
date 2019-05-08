#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "obstacle.h"
#include "moveplayer.h"
#include "worldobject.h"
#include "config.h"
#include <QPainter>

class Obstacles
{
public:
    //not able to configure this constructor correctly, the intent is to create multiple obstacles with different sizes and y values but it isn't working
    Obstacles(Config* config);
    ~Obstacles();

    void render(QPainter &painter);

    //destroy and recreate obstacles when they go outside the screen
    void updateObs();
    //destroy obstacles
    void destroyObs(Obstacle *ob);
    //set velocity
    void setvelocity(int velval);
    int getvelocity();
    std::vector<Obstacle *> obstacless;
private:
    int number, speed, spacing;
    Config *config;
};

#endif // OBSTACLES_H

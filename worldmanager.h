#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include <QPainter>
#include <vector>
#include "worldobjectfactory.h"

class WorldManager {

public:

    // Constructor + Destructor
    WorldManager(Config* config);
    ~WorldManager();

    // Process new frame
    void update(QPainter& painter);

    // Toggle between paused and unpaused
    void togglePause();

    //get velocity
    int getvelocity();
    void setvelocity(int velocity);
private:

    // Attributes
    bool paused = false;
    int velocity;
    QPixmap* pausedSprite;

    // World objects + Factory
    WorldObjectFactory* factory;
    std::vector<WorldObject*> worldObjects;
};

#endif // WORLDMANAGER_H

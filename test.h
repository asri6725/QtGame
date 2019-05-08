#ifndef TEST_H
#define TEST_H
#include <QTimer>
#include <QKeyEvent>
#include "config.h"
#include "player.h"
#include "worldmanager.h"
#include "moveplayer.h"
#include "obstacles.h"


class test
{
public:
    test();
    ~test();

private:

    // Members
    QTimer* timer;
    Config* config;
    Player* player;
    WorldManager* worldManager;
    moveplayer* playerfunc;
    obstacles *ob;
    bool stage2;

public slots:

    // Process next frame
    void nextFrame();

};

#endif // TEST_H

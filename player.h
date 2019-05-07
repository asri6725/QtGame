#ifndef PLAYER_H
#define PLAYER_H

#include <QPainter>
#include <QPixmap>
#include <string>
#include "config.h"
#include "position.h"

class Player{

public:

    // Constructor + Destructor
    Player(Config* config);
    ~Player();

    // Draw
    void render(QPainter& painter);

    // Update size
    void updateDimensions(std::string size);

        Position* pos;
private:

    // Attribures

    std::string size;
    QPixmap* sprite;

};

#endif // PLAYER_H

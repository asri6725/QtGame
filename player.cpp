#include "player.h"
#include "define.h"

// Constructor
Player::Player(Config* config){
    pos = new Position(config->getInitX(), config->getInitY());
    //pos = new Position(0, 0);
    sprite = new QPixmap(config->getPlayerTexture().c_str());
    updateDimensions(config->getSize());
}

// Destructor
Player::~Player(){
    delete pos;
    delete sprite;
}

// Render
void Player::render(QPainter& painter){
    painter.drawPixmap(pos->getX(), pos->getY(), pos->getWidth(), pos->getHeight(), *sprite);
}

// Change dimensions
void Player::updateDimensions(std::string size){

    // Calc new dimensions
    int newWidth = sprite->width();
    int newHeight = sprite->height();
    if(size == "tiny"){
        newWidth *= TINY;
        newHeight *= TINY;
    }
    else if(size == "normal"){
        newWidth *= NORMAL;
        newHeight *= NORMAL;
    }
    else if(size == "large"){
        newWidth *= LARGE;
        newHeight *= LARGE;
    }
    else if(size == "giant"){
        newWidth *= GIANT;
        newHeight *= GIANT;
    }
    else{
      return; // Not legit size so dont update
    }

    // Process update
    this->size = size;
    pos->updateDimensions(newWidth, newHeight);

}

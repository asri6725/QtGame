#include "worldobjectfactory.h"
#include "background.h"
#include "eyecandy.h"
#include "define.h"

// Constructor
WorldObjectFactory::WorldObjectFactory(Config* config){

    // Get eyecandy positions
    airPos = config->getAirPos();
    groundPos = config->getGroundPos();

    // Load textures
    backgroundTexture = new QPixmap(config->getBackgroundTexture().c_str());
    for(std::string airTexture : config->getAirCandyTextures())
        airCandyTextures.push_back(new QPixmap(airTexture.c_str()));
    for(std::string groundTexture : config->getGroundCandyTextures())
        groundCandyTextures.push_back(new QPixmap(groundTexture.c_str()));

}

// Destructor
WorldObjectFactory::~WorldObjectFactory(){
    delete backgroundTexture;
    for(unsigned int i = 0; i < airCandyTextures.size(); i++)
        delete airCandyTextures[i];
    for(unsigned int i = 0; i < groundCandyTextures.size(); i++)
        delete groundCandyTextures[i];
}

// Factory method
WorldObject* WorldObjectFactory::newWorldObject(WorldObjects type, int param){
    if(type == WorldObjects::Background){
        int newWidth = backgroundTexture->width() * (double)(RES_Y / backgroundTexture->height());
        Position* pos = new Position(newWidth*param,0,newWidth,RES_Y);
        return new Background(pos, backgroundTexture);
    }
    else if(type == WorldObjects::AirCandy){
        QPixmap* sprite = airCandyTextures[param];
        Position* pos = new Position(0,airPos,sprite->width(), sprite->height());
        return new EyeCandy(pos, sprite, airPos);
    }
    else if(type == WorldObjects::GroundCandy){
        QPixmap* sprite = groundCandyTextures[param];
        Position* pos = new Position(0,groundPos,sprite->width(), sprite->height());
        return new EyeCandy(pos, sprite, 0);
    }
    else
        return nullptr;
}

// Work out number of background panels required
int WorldObjectFactory::numberBackgroundPanels(){
    int newWidth = backgroundTexture->width() * (double)(RES_Y / backgroundTexture->height());
    return (RES_X/newWidth) + 2;
}

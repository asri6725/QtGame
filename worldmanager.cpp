#include "worldmanager.h"
#include "define.h"

// Constructor
WorldManager::WorldManager(Config* config){

    // Store world velocity
    velocity = config->getVelocity();

    // Build world objects
    factory = new WorldObjectFactory(config);
    int backgroundPanels = factory->numberBackgroundPanels();
    for(int i = 0; i < backgroundPanels; i++)
        worldObjects.push_back(factory->newWorldObject(WorldObjects::Background, i));
    for(unsigned int i = 0; i < config->getAirCandyTextures().size(); i++)
        worldObjects.push_back(factory->newWorldObject(WorldObjects::AirCandy, i));
    for(unsigned int i = 0; i < config->getGroundCandyTextures().size(); i++)
        worldObjects.push_back(factory->newWorldObject(WorldObjects::GroundCandy, i));
    pausedSprite = new QPixmap(config->getPauseTexture().c_str());

}

// Destructor
WorldManager::~WorldManager(){
   for(unsigned int i = 0; i < worldObjects.size(); i++)
       delete worldObjects[i];
   delete factory;
   delete pausedSprite;
}

// Update gamestate - move and draw all objects
void WorldManager::update(QPainter& painter){
    for(unsigned int i = 0; i < worldObjects.size(); i++)
        worldObjects[i]->render(painter);
    if(!paused){
        for(unsigned int i = 0; i < worldObjects.size(); i++)
            worldObjects[i]->updatePosition(-velocity);
    }
    else{
        painter.drawPixmap(0,0,RES_X,RES_Y, *pausedSprite);
    }
}

// Toggle paused state
void WorldManager::togglePause(){paused = !paused;}

int WorldManager::getvelocity(){return this->velocity;}

void WorldManager::setvelocity(int velocity){this->velocity = velocity;}

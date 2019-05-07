#ifndef WORLDOBJECTFACTORY_H
#define WORLDOBJECTFACTORY_H

#include <QPixmap>
#include "config.h"
#include "worldobject.h"

// Types of world objects
enum class WorldObjects{Background, AirCandy, GroundCandy};

class WorldObjectFactory {

public:

    // Constructor + Destructor
    WorldObjectFactory(Config* config);
    ~WorldObjectFactory();

    // Create new object
    WorldObject* newWorldObject(WorldObjects type, int param);

    // Get number of background panels required
    int numberBackgroundPanels();

private:

    // Attributes
    int airPos;
    int groundPos;

    // Textures
    QPixmap* backgroundTexture;
    std::vector<QPixmap*> airCandyTextures;
    std::vector<QPixmap*> groundCandyTextures;

};

#endif // WORLDOBJECTFACTORY_H

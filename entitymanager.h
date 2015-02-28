#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
//#include "parser.h"
#include "componenttypes.h"
#include "component.h"
#include "positioncomponent.h"
#include "velocitycomponent.h"
//#include "hitboxcomponent.h"
#include "spritecomponent.h"
//#include "inputcomponent.h"
//#include "playercomponent.h"
//#include "assetmanager.h"
///#include "world.h"

static const unsigned int MAX_ENTITY_COUNT = 1024;

///Class
class EntityManager
{
protected:

public:

    std::vector<unsigned int> currentID;
    unsigned int nextID;
    unsigned int entityCount;

    std::map<int,int> maskTable;
    std::map<int,std::map<ComponentType, int>> lookupTable;

    std::vector<PositionComponent> positionRegister;
    std::vector<int> freedPosition;
    std::vector<VelocityComponent> velocityRegister;
    std::vector<int> freedVelocity;
    std::vector<SpriteComponent> spriteRegister;
    std::vector<int> freedSprite;

    //std::map<std::string, int> prototype;


    EntityManager();

    void addEntity();
    void removeEntity(int entityID);

    int getComponentIndex(int entityID, ComponentType type);

};

#endif


#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
//#include "parser.h"

#include "entity.h"
//#include "componenttypes.h"
#include "component.h"
#include "positioncomponent.h"
#include "velocitycomponent.h"
//#include "hitboxcomponent.h"
#include "spritecomponent.h"
//#include "inputcomponent.h"
//#include "playercomponent.h"
//#include "assetmanager.h"
///#include "world.h"


///Class
class EntityManager
{
protected:


public:
    unsigned int entityCount = 0;

    //std::map<std::string, Entity> prototypeRegister;
    unsigned int index[MAX_ENTITY_COUNT];
    std::vector<unsigned int> availableID;
    std::vector<Entity> entityRegister;

    EntityManager();

    unsigned int nextID();

    Entity* addEntity();
    bool removeEntity(unsigned int entityID);

    Entity* getEntity(unsigned int entityID);

    void printEntityIDs();

};

#endif

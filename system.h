#ifndef SYSTEM_H
#define SYSTEM_H

#include "entity.h"
#include "componenttypes.h"

///Class
class System
{
protected:

    unsigned int subscriptionMask;
    unsigned int index[MAX_ENTITY_COUNT];
    std::vector<Entity*> entityRegister;

public:

    System(unsigned int inMask) : subscriptionMask(inMask){std::fill_n(index, MAX_ENTITY_COUNT, INVALID);}

    virtual unsigned int getMask(){return subscriptionMask;}

    bool registerEntity(Entity* e)
    {
        if(index[e->getID()] == INVALID)
        {
            if((e->getComponentMask() & subscriptionMask) == subscriptionMask)
            {
                entityRegister.push_back(e);
                index[e->getID()] = entityRegister.size()-1;
                return true;
            }
        }

        std::cout << "Unable to register Entity " << e->getID() << std::endl;
        return false;
    }

    bool deregisterEntity(unsigned int entityID)
    {
        if(index[entityID] != INVALID)
        {
            entityRegister[index[entityID]] = entityRegister[entityRegister.size()-1];
            entityRegister.pop_back();
            index[entityID] = INVALID;
            return true;
        }

        std::cout << "Entity not registered" << std::endl;
        return false;
    }

};

#endif


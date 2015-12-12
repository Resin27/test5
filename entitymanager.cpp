#include "entitymanager.h"

EntityManager::EntityManager()
{
    entityRegister.reserve(MAX_ENTITY_COUNT);
    std::fill_n(index, MAX_ENTITY_COUNT, INVALID);
}

/*bool EntityManager::buildEntity(std::string entityType)
{
    return false;
}*/

unsigned int EntityManager::nextID()
{
    if(entityCount < MAX_ENTITY_COUNT)
    {
        unsigned int newID;
        if(availableID.size())
        {
            newID = availableID.back();
            availableID.pop_back();
        }
        else
        {
            newID = entityCount++;
        }
        return newID;
    }
    return INVALID;
}

Entity* EntityManager::addEntity()
{
    if(entityCount < MAX_ENTITY_COUNT)
    {
        unsigned int entityID = nextID();
        entityRegister.push_back(Entity(entityID));
        index[entityID] = entityRegister.size()-1;
        //std::cout<<"Added Entity " << entityID<<std::endl;
        return &entityRegister.back();
    }
    std::cout << "Register is full, unable to add entity." << std::endl;
    return nullptr;
}


/*bool EntityManager::addEntity()
{
    if(entityCount < MAX_ENTITY_COUNT)
    {
        unsigned int entityID = nextID();
        entityRegister.push_back(Entity(entityID));
        index[entityID] = entityRegister.size()-1;
        std::cout<<"Added Entity " << entityID<<std::endl;
        return true;
    }

    std::cout << "Register is full, unable to add entity." << std::endl;
    return false;
}*/

/*bool EntityManager::addEntity(std::string entityType)
{
    if(entityCount < MAX_ENTITY_COUNT)
    {
        if(prototypeRegister.find(entityType) == prototypeRegister.end())
        {
            ///Use function to build the entity from the script here.
            //prototypeRegister.push_back(Entity())
        }
        //entityRegister.push_back(Entity(nextID++));
        //entityCount++;
        //return true;
    }

    std::cout << "Register is full, unable to add entity." << std::endl;
    return false;
}*/

bool EntityManager::removeEntity(unsigned int entityID)
{
    if(index[entityID] != INVALID)
    {
        entityRegister.erase(entityRegister.begin()+index[entityID]);
        index[entityID] = INVALID;
        --entityCount;
        availableID.push_back(entityID);
        std::cout<<"Removed Entity "<<entityID<<std::endl;
        return true;
    }
    std::cout << "Entity " << entityID << " nonexistent." << std::endl;
    return false;
    /*for(unsigned int i = 0; i < entityRegister.size(); i++)
    {
        if(entityRegister[i].getID() == entityID)
        {
            entityRegister.erase(entityRegister.begin()+i);
            entityCount--;
            return true;
        }
    }

    std::cout << "Entity " << entityID << " nonexistent." << std::endl;
    return false;*/
}

Entity* EntityManager::getEntity(unsigned int entityID)
{
    for(unsigned int i = 0; i < entityRegister.size(); i++)
    {
        if(entityRegister[i].getID() == entityID)
        {
            return &entityRegister[i];
        }
    }

    std::cout << "Entity " << entityID << " nonexistent." << std::endl;
    return nullptr;
}

void EntityManager::printEntityIDs()
{
    for(unsigned int i = 0; i < entityCount; i++)
        std::cout << entityRegister[i].getID() << std::endl;
}

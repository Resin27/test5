#include "movementsystem.h"
#include <iostream>

void MovementSystem::update(float dt)
{
    for(auto &entity : entityRegister)
    {
        PositionComponent& pos = *(entity->get<PositionComponent>());
        VelocityComponent& vel = *(entity->get<VelocityComponent>());
        sf::Vector2f delta = vel.velocity * dt;
        delta = delta + pos.remainder;

        pos.oldPosition = pos.position;
        pos.oldRemainder = pos.remainder;

        pos.position = pos.position + sf::Vector2i(delta);
        pos.remainder.x = (delta.x - sf::Vector2i(delta).x);
        pos.remainder.y = (delta.y - sf::Vector2i(delta).y);
    }
}

/*bool MovementSystem::registerEntity(Entity* e)
{
    if((e->getComponentMask() & subscriptionMask) == subscriptionMask)
    {
        entityRegister.push_back(e);
        ++entityCount;
        return true;
    }

    std::cout << "Unable to register Entity " << e->getID() << std::endl;
    return false;
}

bool MovementSystem::deregisterEntity(unsigned int entityID)
{
    for(unsigned int i = 0; i < entityRegister.size(); ++i)
    {
        if(entityRegister[i]->getID() == entityID)
        {
            entityRegister[i] = entityRegister[entityRegister.size()-1];
            entityRegister.pop_back();
            --entityCount;
            return true;
        }
    }

    std::cout << "Entity not registered" << std::endl;
    return false;
}*/

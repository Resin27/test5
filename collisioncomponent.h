#ifndef COLLISION_COMPONENT_H
#define COLLISION_COMPONENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "component.h"

///Class
class CollisionComponent : public Component
{
protected:

public:

    CollisionComponent(unsigned int inID) : Component(inID){flag = 1<<COMPONENT_COLLISION;}

    ///Can't think. Would an old value of velocity even be helpful?
    //sf::Vector2f oldVelocity;
    sf::FloatRect hitbox;

};

#endif



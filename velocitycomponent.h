#ifndef VELOCITY_COMPONENT_H
#define VELOCITY_COMPONENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "component.h"

///Class
class VelocityComponent : public Component
{
protected:

public:
    ///Can't think. Would an old value of velocity even be helpful?
    //sf::Vector2f oldVelocity;
    sf::Vector2f velocity;

};

#endif


#include "movementsystem.h"
//#include <iostream>

void MovementSystem::update(float dt)
{
    for(unsigned int i = 0; i < positionRegister.size(); i++)
    {
        sf::Vector2f delta = velocityRegister[i]->velocity * dt;
        delta = delta + positionRegister[i]->remainder;

        positionRegister[i]->oldPosition = positionRegister[i]->position;
        positionRegister[i]->oldRemainder = positionRegister[i]->remainder;

        positionRegister[i]->position = positionRegister[i]->position + sf::Vector2i(delta);
        positionRegister[i]->remainder.x = (delta.x - sf::Vector2i(delta).x);
        positionRegister[i]->remainder.y = (delta.y - sf::Vector2i(delta).y);
    }
}

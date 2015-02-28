#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "component.h"

///Class
class PositionComponent : public Component
{
protected:

public:

    sf::Vector2i oldPosition;
    sf::Vector2f oldRemainder;
    sf::Vector2i position;
    sf::Vector2f remainder;

    //PositionComponent(){oldPosition = sf::Vector2f(); position = sf::Vector2f();}
    //PositionComponent(float x, float y){oldPosition = position; oldPositionRemainder = positionRemainder;
    //                                    position = sf::Vector2i(int(x), int(y)); positionRemainder = sf::Vector2f(x - position.x, y - position.y);}
    //PositionComponent(PositionComponent& positionComponent){oldPosition = positionComponent.oldPosition; oldPositionRemainder = positionComponent.oldPositionRemainder;
    //                                                        position = positionComponent.position; positionRemainder = positionComponent.positionRemainder;}

};

#endif

#ifndef DRAW_SYSTEM_H
#define DRAW_SYSTEM_H

#include "system.h"
#include "positioncomponent.h"
#include "spritecomponent.h"

///Class
class DrawSystem : public System
{
protected:

    sf::RenderWindow* window;

public:

    DrawSystem() : System(1<<COMPONENT_POSITION | 1<<COMPONENT_SPRITE){}
    void setWindow(sf::RenderWindow& renderWindow){window = &renderWindow;}

    void update(float dt);

};

#endif


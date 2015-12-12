#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include "system.h"
#include "positioncomponent.h"
#include "velocitycomponent.h"

///Class
class MovementSystem : public System
{
protected:

public:

    MovementSystem() : System(1<<COMPONENT_POSITION | 1<<COMPONENT_VELOCITY){}

    void update(float dt);

};

#endif

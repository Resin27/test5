#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include "system.h"
#include "componenttypes.h"
#include "positioncomponent.h"
#include "velocitycomponent.h"

///Class
class MovementSystem : public System
{
protected:

    //std::vector<PositionComponent*> positionRegister;
    //std::vector<VelocityComponent*> velocityRegister;

public:


    std::vector<PositionComponent*> positionRegister;
    std::vector<VelocityComponent*> velocityRegister;

    MovementSystem(){subscriptionMask = (COMPONENT_POSITION | COMPONENT_VELOCITY);}

    ///Who knows how I want this to work.
    void registerEntity(int entityID);

    void update(float dt);

};

#endif

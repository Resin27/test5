#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "system.h"
#include "positioncomponent.h"
#include "collisioncomponent.h"

///Class
class CollisionSystem : public System
{
protected:

    std::vector<unsigned int> grid[5][5];
    ///Or maybe [15][15] to accommodate the surrounding chunks?

public:

    CollisionSystem() : System(1<<COMPONENT_POSITION | 1<<COMPONENT_COLLISION){}

    void update(float dt);

};

#endif


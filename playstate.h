#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "gamestate.h"

#include "entitymanager.h"
#include "movementsystem.h"
#include "collisionsystem.h"
#include "drawsystem.h"

#include "entity.h"


class PlayState : public GameState
{
protected:

    EntityManager eManager;

    MovementSystem movementSystem;
    CollisionSystem collisionSystem;
    DrawSystem drawSystem;

public:

    void init(GameEngine *game);
    void cleanUp();

    void pause();
    void resume();

    void handleEvents();
    void update(float dt);
    void draw();
};

#endif

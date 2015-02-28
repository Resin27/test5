#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "gamestate.h"

#include "world.h"
#include "entitymanager.h"

#include "object.h"
#include "entity.h"


class PlayState : public GameState
{
protected:

    World world;
    EntityManager eManager;

    Object testObject;
    Entity testEntity;

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

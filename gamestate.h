#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "gameengine.h"

///Class
class GameState
{
protected:

    GameEngine *game;

public:

    virtual void init(GameEngine *game) = 0;
    virtual void cleanUp() = 0;

    virtual void pause() = 0;
    virtual void resume() = 0;

    virtual void handleEvents() = 0;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;

    void changeState(GameEngine *game, GameState *state){game->changeState(state);}
};

#endif


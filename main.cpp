//#include "gameobject.h"
#include "gameengine.h"
#include "playstate.h"
//#include <iostream>

int main()
{
    GameEngine game;

    game.init();
    game.pushState(new PlayState);

    game.run();

    game.cleanUp();

    return 0;
}

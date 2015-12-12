#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

//#include "playstate.h"

#include "inputmanager.h"
#include "assetmanager.h"

class GameState;

///Class
class GameEngine
{
private:

    sf::Clock timer;
    const sf::Time dt = sf::seconds(1.f/30.f);
    sf::Time currentTime;
    sf::Time accumulator;

    unsigned int frameCounter = 0;
    sf::Time frameTimer;

    std::vector<GameState*> states;
    bool running;

public:

    sf::RenderWindow window;
    InputManager inputManager;
    AssetManager assetManager;

    void init();
    void run();
    void cleanUp();

    void changeState(GameState *state);
    void pushState(GameState *state);
    void popState();

    void handleEvents();
    void update();
    void draw();

    bool isRunning(){return running;}
    void quit(){running = false;}
};

#endif

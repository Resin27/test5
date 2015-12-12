#include "gameengine.h"
#include "gamestate.h"

#include <iostream>

void GameEngine::init()
{
    window.create(sf::VideoMode(800, 600), "Here we go again :S");

    //inputManager.configureBindings(&window);

    currentTime = timer.restart();
    accumulator = sf::milliseconds(0);

    running = true;
}

void GameEngine::cleanUp()
{
    while(!states.empty())
    {
        states.back()->cleanUp();
        states.pop_back();
    }
    window.close();
}

void GameEngine::changeState(GameState *state)
{
    if(!states.empty())
    {
        states.back()->cleanUp();
        states.pop_back();
    }

    states.push_back(state);
    states.back()->init(this);
}

void GameEngine::pushState(GameState *state)
{
    if(!states.empty())
        states.back()->pause();

    states.push_back(state);
    states.back()->init(this);
}

void GameEngine::popState()
{
    if(!states.empty())
    {
        states.back()->cleanUp();
        states.pop_back();
    }

    if(!states.empty())
        states.back()->resume();
}

void GameEngine::handleEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
        if(event.type == sf::Event::Closed)
            quit();
    //inputManager.update();
    if(!states.empty())
        states.back()->handleEvents();
}

void GameEngine::update()
{
    sf::Time newTime = timer.getElapsedTime();
    sf::Time frameTime = newTime - currentTime;
    currentTime = newTime;

    ///--------------------------------------------------------------------------
    frameTimer+=frameTime;
    ++frameCounter;
    if(frameTimer.asSeconds() >= 1.f)
    {
        std::cout<<"FPS: " << frameCounter/frameTimer.asSeconds() << std::endl;
        frameCounter = 0;
        frameTimer=sf::seconds(0.f);
    }
    ///--------------------------------------------------------------------------

    accumulator += frameTime;

    while(accumulator >= dt)
    {
        if(!states.empty())
            states.back()->update(dt.asSeconds());
        accumulator -= dt;
    }
}

void GameEngine::draw()
{
    if(!states.empty())
        states.back()->draw();
}

void GameEngine::run()
{
    while(isRunning())
    {
        handleEvents();
        update();
        draw();
    }
}

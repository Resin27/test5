#include "playstate.h"

void PlayState::init(GameEngine *game)
{
    this->game = game;

    game->assetManager.loadTexture("tiles.png");

    Component *posC = new PositionComponent();
    Component *velC = new VelocityComponent();
//    posC->position = sf::Vector2i(1,2);
    testEntity.add(posC);
    //testEntity.add(posC);
    testEntity.add(velC);
    (testEntity.get<PositionComponent>())->position = sf::Vector2i(10,2);
    std::cout << (testEntity.get<PositionComponent>())->position.x << std::endl;
    if(testEntity.get<VelocityComponent>())
        std::cout << "This works!" << std::endl;

    for(int i = 0; i < 128; i++)
        for(int j = 0; j < 128; j++)
        {
            world.currentChunk.tile[j][i].sprite->setTexture(game->assetManager.getTexture("tiles.png"));
            world.currentChunk.tile[j][i].sprite->setTextureRect(sf::IntRect(32,32,32,32));
            world.currentChunk.tile[j][i].sprite->setPosition(j*32, i*32);
        }
}

void PlayState::cleanUp()
{

}

void PlayState::pause()
{

}

void PlayState::resume()
{

}

void PlayState::handleEvents()
{

}

void PlayState::update(float dt)
{

}

void PlayState::draw()
{
    game->window.clear();
    for(int i = 0; i < 128; i++)
            for(int j = 0; j < 128; j++)
                game->window.draw(*(world.currentChunk.tile[j][i].sprite));
    game->window.display();
}

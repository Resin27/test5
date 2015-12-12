#include "playstate.h"

void PlayState::init(GameEngine *game)
{
    this->game = game;

    game->assetManager.loadTexture("tiles.png");
    drawSystem.setWindow(game->window);


//    Message mess(0, COMPONENT_POSITION, 5, 0, 2, 4, 3, 5);
   // mess.printPayload();

    srand(time(NULL));
    int random = rand();
    int random2, random3;
    float quo1, quo2;
   for(unsigned int i = 0; i < 8100; ++i)
   {
        eManager.addEntity();
        Component *pos = new PositionComponent(i);
        Component *vel = new VelocityComponent(i);
        Component *spr = new SpriteComponent(i);


            random2 = rand()%random;
            random3 = rand()%random;
            quo1 = float(random2)/random;
            quo2 = float(random3)/random;

        eManager.entityRegister[i].add(pos);
        eManager.entityRegister[i].add(vel);
        eManager.entityRegister[i].add(spr);
        eManager.entityRegister[i].get<VelocityComponent>()->velocity = sf::Vector2f(20.f*quo1,20.f*quo2);
        //((VelocityComponent*)(eManager.entityRegister[i].get(COMPONENT_VELOCITY)))->velocity = sf::Vector2f(20.f*quo1,20.f*quo2);
        //eManager.entityRegister[i].get<VelocityComponent>()->velocity = sf::Vector2f(20.f,20.f);
        eManager.entityRegister[i].get<SpriteComponent>()->sprite.setTexture(game->assetManager.getTexture("tiles.png"));
        eManager.entityRegister[i].get<SpriteComponent>()->sprite.setTextureRect(sf::IntRect(0,0,32,32));
        movementSystem.registerEntity(&(eManager.entityRegister[i]));
        drawSystem.registerEntity(&(eManager.entityRegister[i]));
   }
    /*eManager.addEntity();
    eManager.entityRegister[0].add(pos);
    eManager.entityRegister[0].add(vel);
    eManager.entityRegister[0].add(spr);
    eManager.entityRegister[0].get<VelocityComponent>()->velocity = sf::Vector2f(24.f,15.f);
    eManager.entityRegister[0].get<SpriteComponent>()->sprite.setTexture(game->assetManager.getTexture("tiles.png"));
    eManager.entityRegister[0].get<SpriteComponent>()->sprite.setTextureRect(sf::IntRect(0,0,32,32));

    mover.registerEntity(&(eManager.entityRegister[0]));*/
    /*for(unsigned int i = 0; i < 20; i++)
        eManager.addEntity();
    for(unsigned int i = 0; i < 20; i++)
        if(i%2 == 0)
            eManager.removeEntity(i);
    eManager.printEntities();*/

    /*for(unsigned int i = 0; i < 5; i++)
    {
        eManager.addEntity();
        Component *pos = new PositionComponent(i);
        if(i%2)
        {
            Component *vel = new VelocityComponent(i);
            eManager.entityRegister[i].add(vel);
        }
        eManager.entityRegister[i].add(pos);

        if(eManager.entityRegister[i].getComponentMask() == mover.getMask())
        {
            mover.registerEntity(&(eManager.entityRegister[i]));
            std::cout << "Registered entity " << i << std::endl;
        }
        std::cout << "Mask for entity " << i << " is: " << eManager.entityRegister[i].getComponentMask() << std::endl;
    }*/

    /*for(int i = 0; i < 128; i++)
        for(int j = 0; j < 128; j++)
        {
            world.currentChunk.tile[j][i].sprite->setTexture(game->assetManager.getTexture("tiles.png"));
            world.currentChunk.tile[j][i].sprite->setTextureRect(sf::IntRect(32,32,32,32));
            world.currentChunk.tile[j][i].sprite->setPosition(j*32, i*32);
        }*/
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
    movementSystem.update(dt);
    //std::cout<<"Last entityID: "<< eManager.addNewEntity()->getID()<<std::endl;
    //eManager.entityRegister[0].get<SpriteComponent>()->sprite.setPosition(sf::Vector2f(eManager.entityRegister[0].get<PositionComponent>()->position));

}

void PlayState::draw()
{
    drawSystem.update(0);
    //game->window.clear();
    /*for(int i = 0; i < 128; i++)
            for(int j = 0; j < 128; j++)
                game->window.draw(*(world.currentChunk.tile[j][i].sprite));*/
    /*for(unsigned int i = 0; i < eManager.entityCount; ++i)
    {
        eManager.entityRegister[i].get<SpriteComponent>()->sprite.setPosition(sf::Vector2f(eManager.entityRegister[i].get<PositionComponent>()->position));
        game->window.draw(eManager.entityRegister[i].get<SpriteComponent>()->sprite);
    }*/
    //game->window.draw(eManager.entityRegister[0].get<SpriteComponent>()->sprite);
    //game->window.display();
}

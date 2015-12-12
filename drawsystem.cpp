#include "drawsystem.h"

void DrawSystem::update(float dt)
{
    window->clear();
    for(auto &entity : entityRegister)
    {
        PositionComponent& pos = *(entity->get<PositionComponent>());
        SpriteComponent& spr = *(entity->get<SpriteComponent>());
        spr.sprite.setPosition(sf::Vector2f(pos.position));
        window->draw(spr.sprite);
    }
    window->display();
}

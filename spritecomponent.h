#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "component.h"

///Class
class SpriteComponent : public Component
{
protected:

public:

    sf::Texture *texture;
    sf::Sprite sprite;

};

#endif


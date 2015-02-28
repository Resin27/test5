#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>

///Class
class AssetManager
{
protected:

    std::map<std::string, sf::Texture> loadedTexture;
    std::map<std::string, sf::Font> loadedFont;

public:

    //AssetManager(){};

    sf::Texture& getTexture(std::string textureFile);
    sf::Font& getFont(std::string fontFile);

    bool loadTexture(std::string textureFile);
    bool loadFont(std::string fontFile);
};

#endif

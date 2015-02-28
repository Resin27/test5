#include "assetmanager.h"

sf::Texture& AssetManager::getTexture(std::string textureFile)
{
    std::map<std::string, sf::Texture>::iterator it = loadedTexture.find(textureFile);
    if(it == loadedTexture.end())
    {
        if(!loadedTexture[textureFile].loadFromFile(textureFile))
        {
            std::cout << "Unable to load texture from " << textureFile << std::endl;
        }
    }

    return loadedTexture[textureFile];
}

sf::Font& AssetManager::getFont(std::string fontFile)
{
    std::map<std::string, sf::Font>::iterator it = loadedFont.find(fontFile);
    if(it == loadedFont.end())
    {
        if(!loadedFont[fontFile].loadFromFile(fontFile))
        {
            std::cout << "Unable to load font from " << fontFile << std::endl;
        }
    }

    return loadedFont[fontFile];
}

bool AssetManager::loadTexture(std::string textureFile)
{
    //if(!loadedTexture[textureFile].loadFromFile(textureFile))
    //    std::cout << "Whoops!" << std::endl;
    return loadedTexture[textureFile].loadFromFile(textureFile);
}

bool AssetManager::loadFont(std::string fontFile)
{
    //if(!loadedFont[fontFile].loadFromFile(fontFile))
    //    std::cout << "Whoops!" << std::endl;
    return loadedFont[fontFile].loadFromFile(fontFile);
}

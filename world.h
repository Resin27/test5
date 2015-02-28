
#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>



///Classes

class Tile
{
protected:

public:
    sf::Vector2i position;
    sf::Vector2i hitbox;
    sf::Sprite *sprite;

    Tile(){position = {0,0}; hitbox = {0,0}; sprite = new sf::Sprite();}
};

struct Chunk
{
protected:

public:
    //int IDx, IDy;
    Tile tile[300][200];
};

class World
{
protected:


public:

    Chunk currentChunk;

    //std::vector<Chunk> inactiveChunk;
    //Chunk activeChunk[3][3];
    //Chunk currentChunk;

///   This idea here is that the 2D array of current chucks simply contains the ID of the active chunks.
///   The ID is then used to lookup the chunk in the vector of chunks. From there we access the tiles.
//    std::vector<Chunk> chunk;
//    int activeChunk[3][3];
//
//    active[0][0] = chunk[2];
//    active[0][1] = chunk[3;]

    //World(){};

};

#endif

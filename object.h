#ifndef OBJECT_H
#define OBJECT_H

static const int NUM_OF_FLAGS = 5;

enum Flag
{
    F_Visible = 0,
    F_Mobile,
    F_Animate,
    F_Material,
    F_Interactable
};

///Class
class Object
{
protected:

    unsigned int ID;
    unsigned int uniqueID;
    std::string tag;
    std::string uniqueTag;

    ///Turn this into the componentMask
    bool flagRegister[NUM_OF_FLAGS];

    /*std::vector<Component*> componentRegister;*/

    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::IntRect  hitbox;

    /*PhysicsComponent *physics;
    RenderComponent  *redner;
    BehaviorComponent *behavior;*/

public:

    //bool isFlag(Flag f){return flagRegister[f];}


};

#endif


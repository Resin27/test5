#ifndef ENTITY_H
#define ENTITY_H

#include "component.h"
//#include "positioncomponent.h"

//static const int NUM_OF_FLAGS = 5;

/*enum Flag
{
    F_Visible = 0,
    F_Mobile,
    F_Animate,
    F_Material,
    F_Interactable
};*/

///Class
class Entity
{
protected:

    unsigned int ID;
    unsigned int uniqueID;
    std::string tag;
    std::string uniqueTag;

    ///Turn this into the componentMask
    //bool flagRegister[NUM_OF_FLAGS];

    /*std::vector<Component*> componentRegister;*/

    std::vector<Component*> componentRegister;
    /*sf::Vector2f position;
    sf::Vector2f velocity;
    sf::IntRect  hitbox;*/

    /*PhysicsComponent *physics;
    RenderComponent  *redner;
    BehaviorComponent *behavior;*/

public:

    void add(Component* c)
    {
        componentRegister.push_back(c);
    }

    template <class T>
    T* get()
    {
        for(unsigned int i = 0; i < componentRegister.size(); i++)
        {
            T* ptr = dynamic_cast<T*>(componentRegister[i]);
            if(ptr != nullptr)
                return ptr;
        }
        return nullptr;
    }


};

#endif


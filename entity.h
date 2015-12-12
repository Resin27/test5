#ifndef ENTITY_H
#define ENTITY_H

//#include <iostream>

//#include <stdarg.h>
#include <string>
#include <vector>
#include <iostream>
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

/*class Message
{
protected:
    unsigned int ID;
    ComponentType concernedComponent;
    std::vector<int> payload;
public:

    Message(unsigned int inID, ComponentType inComp, int arg, ...)
    {
        ID = inID;
        concernedComponent = inComp;
        va_list v1;
        va_start(v1, arg);
        for(int i = 0; i < arg; i++)
        {
            payload.push_back(va_arg(v1,int));
        }
        va_end(v1);
    }

    void printPayload()
    {
        for(int i = 0; i < payload.size(); i++)
            std::cout << i << ":" << payload[i] << std::endl;
    }

};*/

static const unsigned int MAX_ENTITY_COUNT = 65535;
static const unsigned int INVALID = -1;

///Class
class Entity
{
protected:

    unsigned int ID;
    //unsigned int uniqueID;
    std::string tag;
    //std::string uniqueTag;

    unsigned int componentMask;
    ///Turn this into the componentMask
    //bool flagRegister[NUM_OF_FLAGS];

    std::vector<Component*> componentRegister;

public:

    Entity() : componentMask(0){};
    Entity(unsigned int inID) : ID(inID), componentMask(0){};
    Entity(unsigned int inID, std::string inTag) : ID(inID), tag(inTag), componentMask(0){};

    unsigned int getID(){return ID;}
    unsigned int getComponentMask(){return componentMask;}
    void setTag(std::string inTag){tag = inTag;}
    std::string getTag(){return tag;}

    bool add(Component* c)
    {
        if((componentMask & c->getFlag()) == 0)
        {
            componentRegister.push_back(c);
            componentMask |= c->getFlag();
            return true;
        }

        return false;
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


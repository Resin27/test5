#ifndef COMPONENT_H
#define COMPONENT_H

#include "componenttypes.h"

///Class
class Component
{
protected:

    unsigned int entityID;
    unsigned int flag;

public:

    Component(unsigned int inID) : entityID(inID){}

    virtual unsigned int getID(){return entityID;}
    virtual unsigned int getFlag(){return flag;}

};

#endif

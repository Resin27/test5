#ifndef COMPONENT_H
#define COMPONENT_H

///Class
class Component
{
protected:

    unsigned int entityID;

public:

    virtual unsigned int getID(){return entityID;}

};

#endif

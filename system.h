#ifndef SYSTEM_H
#define SYSTEM_H

///Class
class System
{
protected:

    unsigned int subscriptionMask;

public:

    virtual unsigned int getMask(){return subscriptionMask;}
    //unsigned int subscriptionMask;

};

#endif


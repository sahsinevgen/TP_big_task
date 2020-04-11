#ifndef OBJECTFABRIC_H
#define OBJECTFABRIC_H

#include "../objects/Object.h"

enum Object_ID {Warrior_ID = 0, Archer_ID, Cavalry_ID};

class ObjectFabric
{
public:
    ObjectFabric();
    virtual Object* create_object(Object_ID ID) = 0;
};

#endif // OBJECTFABRIC_H

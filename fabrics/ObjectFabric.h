#ifndef OBJECTFABRIC_H
#define OBJECTFABRIC_H

#include "../objects/Object.h"

enum Object_ID {Warrior_ID = 0, Archer_ID};

class ObjectFabric
{
public:
    ObjectFabric(QWidget *parent = 0);
    virtual Object* create_object(Object_ID ID) = 0;
    virtual ~ObjectFabric() {};
protected:
    QWidget *parent;
};

#endif // OBJECTFABRIC_H

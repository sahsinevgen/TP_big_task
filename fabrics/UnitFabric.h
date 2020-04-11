#ifndef UNITFABRIC_H
#define UNITFABRIC_H

#include "ObjectFabric.h"
#include "../objects/units/Unit.h"

class UnitFabric: public ObjectFabric
{
public:
    UnitFabric();
    virtual Unit* create_unit(Object_ID ID) = 0;
    Object* create_object(Object_ID ID);
};

#endif // UNITFABRIC_H

#ifndef GOODFABRIC_H
#define GOODFABRIC_H

#include "UnitFabric.h"
#include "../objects/units/HumanWarrior.h"
#include "../objects/units/ElfArcher.h"
#include "../objects/units/GoodCavalry.h"

class GoodFabric: public UnitFabric
{
public:
    GoodFabric();
    Unit* create_unit(Object_ID ID);
};

#endif // GOODFABRIC_H

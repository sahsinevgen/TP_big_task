#ifndef EVILFABRIC_H
#define EVILFABRIC_H

#include "UnitFabric.h"
#include "../objects/units/DemonWarrior.h"
#include "../objects/units/SkeletonArcher.h"
#include "../objects/units/EvilCavalry.h"

class EvilFabric: public UnitFabric
{
public:
    EvilFabric();
    Unit* create_unit(Object_ID ID);
};

#endif // EVILFABRIC_H

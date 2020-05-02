#ifndef EVILFABRIC_H
#define EVILFABRIC_H

#include "UnitFabric.h"
#include "../objects/units/DemonWarrior.h"
#include "../objects/units/SkeletonArcher.h"

class EvilFabric: public UnitFabric
{
public:
    EvilFabric(QWidget *parent = 0);
    Unit* create_unit(Object_ID ID);
};

#endif // EVILFABRIC_H

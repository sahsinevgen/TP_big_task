#ifndef GOODFABRIC_H
#define GOODFABRIC_H

#include "UnitFabric.h"
#include "../objects/units/HumanWarrior.h"
#include "../objects/units/ElfArcher.h"

class GoodFabric: public UnitFabric
{
public:
    GoodFabric(QWidget *parent = 0);
    Unit* create_unit(Object_ID ID);
};

#endif // GOODFABRIC_H

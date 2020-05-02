#ifndef ECONOMICARMY_H
#define ECONOMICARMY_H

#include "Army.h"
#include "../../fabrics/UnitFabric.h"

class EconomicArmy: public Army
{
public:
    EconomicArmy(UnitFabric *fab);
    void do_action();
    void spawn();
protected:
    UnitFabric *fab;
    int spawn_cooldawn;
    int tyme_to_spawn;
};

#endif // ECONOMICARMY_H

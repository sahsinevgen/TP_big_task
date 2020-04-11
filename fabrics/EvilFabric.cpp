#include "EvilFabric.h"

EvilFabric::EvilFabric()
{

}

Unit* EvilFabric::create_unit(Object_ID ID) {
    Unit* x;
    switch (ID) {
    case Warrior_ID:
        x = new DemonWarrior();
        break;
    case Archer_ID:
        x = new SkeletonArcher();
        break;
    case Cavalry_ID:
        x = new EvilCavalry();
        break;
    default:
        break;
    }
    return x;
}

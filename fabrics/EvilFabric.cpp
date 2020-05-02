#include "EvilFabric.h"

EvilFabric::EvilFabric(QWidget *parent):
    UnitFabric(parent)
{

}

Unit* EvilFabric::create_unit(Object_ID ID) {
    Unit* x;
    switch (ID) {
    case Warrior_ID:
        x = new DemonWarrior(parent);
        break;
    case Archer_ID:
        x = new SkeletonArcher(parent);
        break;
    default:
        break;
    }
    return x;
}

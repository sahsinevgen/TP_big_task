#include "GoodFabric.h"

GoodFabric::GoodFabric(QWidget *parent):
    UnitFabric(parent)
{

}

Unit* GoodFabric::create_unit(Object_ID ID) {
    Unit* x;
    switch (ID) {
    case Warrior_ID:
        x = new HumanWarrior(parent);
        break;
    case Archer_ID:
        x = new ElfArcher(parent);
        break;
    default:
        break;
    }
    return x;
}

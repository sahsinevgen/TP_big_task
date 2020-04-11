#include "GoodFabric.h"

GoodFabric::GoodFabric()
{

}

Unit* GoodFabric::create_unit(Object_ID ID) {
    Unit* x;
    switch (ID) {
    case Warrior_ID:
        x = new HumanWarrior();
        break;
    case Archer_ID:
        x = new ElfArcher();
        break;
    case Cavalry_ID:
        x = new GoodCavalry();
        break;
    default:
        break;
    }
    return x;
}

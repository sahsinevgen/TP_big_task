#include "EconomicArmy.h"

EconomicArmy::EconomicArmy(UnitFabric* fab):
    Army()
{
    this->fab = fab;
    this->spawn_cooldawn = 50;
    this->tyme_to_spawn = this->spawn_cooldawn;
}

void EconomicArmy::do_action()
{
    this->Army::do_action();
    spawn();
}

void EconomicArmy::spawn()
{
    if (this->has_target || this->is_dead())
    {
        this->tyme_to_spawn = this->spawn_cooldawn;
        return;
    }
    if (this->tyme_to_spawn > 0)
    {
        this->tyme_to_spawn--;
        return;
    }
    Unit *unit = fab->create_unit(Warrior_ID);
    this->add_Unit(unit);
    unit->set_position(this->get_position());
    this->tyme_to_spawn = this->spawn_cooldawn;
}

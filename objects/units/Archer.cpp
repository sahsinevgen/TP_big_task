#include "Archer.h"

Archer::Archer(QString path_to_image, QString type, QWidget *parent):
    Unit(path_to_image, type, 40, 2, 15, 200, 8, parent)
{

}

void Archer::attack(Unit *target)
{
    this->time_to_action = this->attack_cooldown;
    this->arrows.push_back(new Arrow(target, this->damage, parent));
    arrows[arrows.size() - 1]->set_position(this->position);
}

void Archer::do_action()
{
    this->Unit::do_action();
    for (int i = 0; i < this->arrows.size(); i++)
    {
        this->arrows[i]->do_action();
    }
}

void Archer::draw()
{
    this->Unit::draw();
    for (int i = 0; i < this->arrows.size(); i++)
    {
        this->arrows[i]->draw();
    }
}

Archer::~Archer()
{
    for (int i = 0; i < this->arrows.size(); i++)
    {
        delete this->arrows[i];
    }
}

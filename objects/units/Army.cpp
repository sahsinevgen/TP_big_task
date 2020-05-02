#include "Army.h"

Army::Army():
    Unit()
{
    this->has_target = false;
}

bool Army::is_destroyed()
{
    for (int i = 0; i < this->c.size(); i++)
    {
        if (!this->c[i]->is_destroyed())
            return false;
    }
    return true;
}

void Army::add_Unit(Unit *p)
{
    this->c.push_back(p);
}

void Army::do_action()
{
    for (int i = 0; i < this->c.size(); i++)
    {
        if (this->c[i]->has_target)
        {
            this->c[i]->do_action();
        }
        else
        {
            if (this->has_target)
            {

                Unit* attack_target = target->get_target(this->c[i]);
                if (attack_target == nullptr) {
                    this->target = nullptr;
                    this->has_target = false;
                    return;
                }
                this->c[i]->change_target(attack_target);
            }
            else
            {
                int dx = rand() % (2 * radius - 1) - radius;
                int dy = rand() % (2 * radius - 1) - radius;
                this->c[i]->change_target(this->get_position().inc(Point(dx, dy)));
            }
        }
    }
}

Unit* Army::get_target(Unit* another)
{
    Unit* target;
    target = nullptr;
    for (int i = 0; i < this->c.size(); i++)
    {
        if (this->c[i]->is_destroyed())
        {
            continue;
        }
        Unit* new_target = this->c[i]->get_target();
        if (new_target != nullptr &&
                (target == nullptr ||
                 another->get_position().dist(target->get_position()) > another->get_position().dist(new_target->get_position())))
        {
            target = new_target;
        }
    }
    return target;
}

void Army::change_target(Unit* target)
{
    this->change_target();
    this->target = target;
    this->has_target = true;
}

void Army::change_target(Point target_pos)
{
    this->change_target();
    this->set_position(target_pos);
}

void Army::change_target()
{
    for (int i = 0; i < this->c.size(); i++)
    {
        this->c[i]->change_target();
    }
}

void Army::draw()
{
    for (int i = 0; i < this->c.size(); i++)
    {
        this->c[i]->draw();
    }
}

Army::~Army() {
    for (int i = 0; i < this->c.size(); i++)
    {
        delete this->c[i];
    }
}

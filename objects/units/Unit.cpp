#include "Unit.h"

Unit::Unit():
    Object()
{

}

Unit::Unit(QString path_to_image, QString type, int max_health, int speed, int damage, int range, int attack_cooldown, QWidget *parent):
    Object(path_to_image, type, parent)
{
    this->health = this->max_health = max_health;
    this->speed = speed;
    this->damage = damage;
    this->range = range;
    this->time_to_action = 0;
    this->target = nullptr;
    this->has_target = false;
    this->attack_cooldown = attack_cooldown;
}

bool Unit::is_dead()
{
    return this->health <= 0;
}

bool Unit::is_destroyed()
{
    return this->is_dead();
}

bool Unit::ready() 
{
    return this->time_to_action <= 0;
}

bool Unit::can_attack(Unit* target)
{
    return (this->get_position().dist(target->get_position()) < range);
}

void Unit::attack(Unit* target)
{
    this->time_to_action = this->attack_cooldown;
    target->damaged(this->damage);
}

void Unit::damaged(int damage)
{
    this->health -= damage;
}

void Unit::move(Point direction)
{
    Point pos = this->get_position();
    double dist = pos.dist(direction);
    if (dist < this->speed)
        this->set_position(direction);
    else
        this->set_position(pos.inc((direction.dec(pos)).mult(this->speed / dist)));
}

void Unit::do_action()
{
    if (this->is_destroyed())
    {
        return;
    }
    if (!this->ready())
    {
        this->time_to_action--;
        return;
    }
    if (this->has_target)
    {
        if (this->target != nullptr)
        {
            if (this->target->is_dead())
            {
                this->change_target();
                return;
            }
            if (this->can_attack(this->target))
            {
                this->attack(this->target);
            }
            else
            {
                this->move(this->target->get_position());
            }
        }
        else
        {
            if (this->get_position().dist(this->target_pos) < this->speed)
            {
                this->change_target();
            }
            this->move(this->target_pos);
        }
    }
}

Unit* Unit::get_target(Unit *another)
{
    return this;
}

void Unit::change_target(Unit* target)
{
    this->has_target = true;
    this->target = target;
}

void Unit::change_target(Point target_pos)
{
    this->has_target = true;
    this->target = nullptr;
    this->target_pos = target_pos;
}

void Unit::change_target()
{
    this->has_target = false;
    this->target = nullptr;
}

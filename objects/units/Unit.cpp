#include "Unit.h"

Unit::Unit(QString path_to_image, QString type, int max_health, int speed, int damage, int range):
    Object(path_to_image, type)
{
    this->health = this->max_health = max_health;
    this->speed = speed;
    this->damage = damage;
    this->range = range;
    this->time_to_action = 0;
    this->target_id = -1;
}

bool Unit::is_dead()
{
    return this->health <= 0;
}

bool Unit::ready() 
{
    return this->time_to_action = 0;
}

bool Unit::can_attack(Unit* target)
{
    return (this->dist(target) < range);
}

void Unit::attack(Unit* target) {
    target->get_damage(this->damage);
}

void Unit::get_damage(int damage)
{
    this->health -= damage;
}

void Unit::move(QPair<double, double> direction)
{
    double x = this->get_position().first;
    double y = this->get_position().second;
    double x2 = direction.first;
    double y2 = direction.second;
    double dx = x2 - x;
    double dy = y2 - y;
    double dist = qSqrt(dx * dx + dy * dy);
    if (dist < this->speed)
        this->set_position(QPair<double, double>(x2, y2));
    else
        this->set_position(QPair<double, double>(x + dx * speed / dist, y + dy * speed / dist));
}

void Unit::change_target(int target_id)
{
    this->target_id = target_id;
}

int Unit::get_target_id()
{
    return this->target_id;
}

bool Unit::has_target()
{
    return this->target_id != -1;
}

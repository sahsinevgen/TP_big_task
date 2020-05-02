#include <QPainter>
#include "Arrow.h"

Arrow::Arrow(Unit* target, int damage, QWidget *parent):
    Unit(QDir::currentPath()+"/../resourse/image/arrow.png", "Arrow", 1, 10, damage, 10, 1, parent)
{
    this->target = target;
    this->has_target = true;
    this->attacked = false;
}

void Arrow::attack(Unit *target)
{
    this->Unit::attack(target);
    attacked = true;
}

void Arrow::do_action()
{
    if (this->is_destroyed())
    {
        return;
    }
    if (this->target != nullptr)
    {
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
        this->attacked = true;
    }
}

bool Arrow::is_destroyed()
{
    return this->attacked;
}

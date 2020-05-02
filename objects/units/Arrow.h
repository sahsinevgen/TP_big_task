#ifndef ARROW_H
#define ARROW_H

#include "./Unit.h"

class Arrow: public Unit
{
public:
    Arrow(Unit* target, int damage, QWidget *parent = 0);
    void attack(Unit* target);
    void do_action();
    bool is_destroyed();
private:
    bool attacked;
};

#endif // ARROW_H

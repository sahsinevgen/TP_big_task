#ifndef ARMY_H
#define ARMY_H

#include <QVector>
#include "Unit.h"

class Army: public Unit
{
public:
    Army();
    bool is_destroyed();
    void add_Unit(Unit* p);
    virtual void do_action();
    Unit* get_target(Unit *another);
    void change_radius(int radius);
    void change_target(Unit* target);
    void change_target(Point target_pos);
    void change_target();
    void draw();
    ~Army();
private:
    QVector<Unit*> c;
    int radius = 50;
};

#endif // ARMY_H

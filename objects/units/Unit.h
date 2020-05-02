#ifndef UNIT_H
#define UNIT_H

#include "../Object.h"

class Unit: public Object
{
public:
    Unit();
    Unit(QString path_to_image, QString type, int max_health, int speed, int damage, int range, int attack_cooldown, QWidget *parent = 0);
    virtual bool is_dead();
    bool is_destroyed();
    bool can_attack(Unit* target);
    virtual void attack(Unit* target);
    void move(Point direction);
    virtual void do_action();
    virtual Unit* get_target(Unit* another = nullptr);
    bool ready();
    virtual void change_target(Unit* target);
    virtual void change_target(Point target_pos);
    virtual void change_target();

    void damaged(int damage);
    bool has_target;
protected:
    Unit* target;
    Point target_pos;
//private:
    int health;
    int max_health;
    int speed;
    int damage;
    int range;
    int time_to_action;
    int attack_cooldown;
};

#endif // UNIT_H

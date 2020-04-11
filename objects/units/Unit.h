#ifndef UNIT_H
#define UNIT_H

#include "../Object.h"

class Unit: public Object
{
public:
    Unit(QString path_to_image, QString type, int max_health, int speed, int damage, int range);
    bool is_dead();
    bool can_attack(Unit* target);
    void attack(Unit* target);
    void move(QPair<double, double> direction);
    bool ready();
    void change_target(int target_id);
    int get_target_id();
    bool has_target();
    void get_damage(int damage);
private:
    int health;
    int max_health;
    int speed;
    int damage;
    int range;
    int time_to_action;
    int target_id;
    //bool have
};

#endif // UNIT_H

#ifndef WARRIOR_H
#define WARRIOR_H

#include "Unit.h"

class Warrior: public Unit
{
public:
    Warrior(QString path_to_image, QString type = "Warrior", QWidget *parent = 0);
};

#endif // WARRIOR_H

#ifndef ARCHER_H
#define ARCHER_H

#include "Unit.h"

class Archer: public Unit
{
public:
    Archer(QString path_to_image, QString type = "Archer");
};

#endif // ARCHER_H

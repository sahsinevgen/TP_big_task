#ifndef CAVALRY_H
#define CAVALRY_H

#include "Unit.h"

class Cavalry: public Unit
{
public:
    Cavalry(QString path_to_image, QString type = "Cavalry");
};

#endif // CAVALRY_H

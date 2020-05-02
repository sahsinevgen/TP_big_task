#ifndef ARCHER_H
#define ARCHER_H

#include <QVector>
#include "Unit.h"
#include "Arrow.h"

class Archer: public Unit
{
public:
    Archer(QString path_to_image, QString type = "Archer", QWidget *parent = 0);
    void attack(Unit* target);
    void do_action();
    void draw();
    ~Archer();
protected:
    QVector<Unit*> arrows;
};

#endif // ARCHER_H

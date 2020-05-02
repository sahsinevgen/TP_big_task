#ifndef OBJECT_H
#define OBJECT_H

#include <QString>
#include <QPair>
#include <QDir>

#include <iostream>
#include <QPixmap>
#include <QLabel>
#include "Point.h"

namespace Ui {
class Object;
}

class Object
{
public:
    Object();
    Object(QString path_to_image, QString type, QWidget *parent = 0);
    int get_id();
    void set_position(Point position);
    Point get_position();
    QString get_path_to_image();
    virtual bool is_destroyed() = 0;
    virtual ~Object();
    virtual void draw();
protected:
    QString path_to_image;
    QString type;
    int id;
    Point position;
    static int counter;
    QWidget *parent;
    QLabel *label;
};

#endif // OBJECT_H

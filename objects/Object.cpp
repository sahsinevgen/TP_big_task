#include "Object.h"

int Object::counter = 0;

Object::Object(QString path_to_image, QString type)
{
    this->id = counter++;
    this->path_to_image = path_to_image;
    this->type = type;
    //this->position = position;
}

int Object::get_id()
{
    return this->id;
}

void Object::set_position(QPair<double, double> position)
{
    this->position = position;
}

QPair<double, double> Object::get_position()
{
    return this->position;
}

QString Object::get_path_to_image()
{
    return this->path_to_image;
}

double Object::dist(Object* another)
{
    double x = this->get_position().first;
    double y = this->get_position().second;
    double x2 = another->get_position().first;
    double y2 = another->get_position().second;
    double dx = x2 - x;
    double dy = y2 - y;
    return qSqrt(dx * dx + dy * dy);
}

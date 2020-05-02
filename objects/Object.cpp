#include "Object.h"

int Object::counter = 0;

Object::Object()
{

}

Object::Object(QString path_to_image, QString type, QWidget *parent)
{
    this->id = counter++;
    this->path_to_image = path_to_image;
    this->type = type;
    this->parent = parent;
    this->label = new QLabel(parent);
    this->label->setPixmap(QPixmap(path_to_image));
}

int Object::get_id()
{
    return this->id;
}

void Object::set_position(Point position)
{
    this->position = position;
}

Point Object::get_position()
{
    return this->position;
}

QString Object::get_path_to_image()
{
    return this->path_to_image;
}

void Object::draw() {
    if (this->is_destroyed())
    {
        this->label->hide();
    }
    else
    {
        this->label->show();
    }
    label->setGeometry(this->position.x, this->position.y, 64, 64);

}

Object::~Object()
{
    delete this->label;
}

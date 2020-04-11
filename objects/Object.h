#ifndef OBJECT_H
#define OBJECT_H

#include <QString>
#include <QPair>
#include <QtMath>
#include <QDir>

class Object
{
public:
    Object(QString path_to_image, QString type);
    int get_id();
    void set_position(QPair<double, double> position);
    QPair<double, double> get_position();
    QString get_path_to_image();
    double dist(Object* another);
private:
    QString path_to_image;
    QString type;
    int id;
    QPair<double, double> position;
    static int counter;
};

#endif // OBJECT_H

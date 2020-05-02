#ifndef POINT_H
#define POINT_H

#include <QtMath>

class Point
{
public:
    Point(double x = 0, double y = 0);
    Point inc(Point a);
    Point dec(Point a);
    Point mult(double a);
    Point div(double a);
    double len();
    double dist(Point a);
    double x;
    double y;
};

#endif // POINT_H

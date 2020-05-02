#include "Point.h"

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point Point::inc(Point a)
{
    return Point(this->x + a.x, this->y + a.y);
}

Point Point::dec(Point a)
{
    return Point(this->x - a.x, this->y - a.y);
}

Point Point::mult(double a)
{
    return Point(this->x * a, this->y * a);
}

Point Point::div(double a)
{
    return Point(this->x / a, this->y / a);
}

double Point::len()
{
    return qSqrt(this->x * this->x + this->y * this->y);
}

double Point::dist(Point a)
{
    return this->dec(a).len();
}

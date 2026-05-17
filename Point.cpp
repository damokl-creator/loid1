//
// Created by D on 21.04.2026.
//

#include "Point.h"
Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}
double Point::getX() const
{
    return this->x;
}
double Point::getY() const
{
    return this->y;
}
bool Point::isEqual(double a, double b)
{
    const double EPSILON = 1e-9;
    return std::abs(a - b) < EPSILON;
}

bool Point::operator==(const Point& p) const {
    return isEqual(x, p.x) && isEqual(y, p.y);
}

bool Point::operator!=(const Point& p) const
{
    return !(*this == p);
}

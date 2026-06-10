//
// Created by D on 21.04.2026.
//

#include <limits>
#include "Point.h"

Point::Point(const double x, const double y)
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
bool Point::isEqual(const double a, const double b)
{
    return std::abs(a - b) < std::numeric_limits<double>::epsilon();
}

bool Point::operator==(const Point& p) const {
    return isEqual(x, p.x) && isEqual(y, p.y);
}

bool Point::operator!=(const Point& p) const
{
    return !(*this == p);
}

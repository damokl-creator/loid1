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
bool Point::operator==(Point p) const
{
    if (this->x == p.x && this->y == p.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Point::operator!=(Point p) const
{
    if (this->x != p.x || this->y != p.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
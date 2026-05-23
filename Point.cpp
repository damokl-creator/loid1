#include "Point.h"
#include <cmath>
#include <stdexcept>

const double Point::EPS = std::numeric_limits<double>::epsilon() * 1e7;
double Point::maxCoord = 1000.0;

Point::Point(const double x, const double y) : x(x), y(y)
{
    if (x < 0 || x > maxCoord + EPS || y < 0 || y > maxCoord + EPS)
        throw std::out_of_range("Point coordinates out of screen bounds");
}

void Point::setMaxCoord(double max)
{
    if (max > 0)
        maxCoord = max;
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

bool Point::operator==(const Point& other) const
{
    return std::abs(x - other.x) <= EPS && std::abs(y - other.y) <= EPS;
}

bool Point::operator!=(const Point& other) const
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p)
{
    is >> p.x >> p.y;
    if (p.x < 0 || p.x > Point::maxCoord + Point::EPS ||
        p.y < 0 || p.y > Point::maxCoord + Point::EPS)
        throw std::out_of_range("Point coordinates out of screen bounds");
    return is;
}

Point Point::operator+(int val) const
{
    return Point(x + val, y + val);
}

Point Point::operator-(int val) const
{
    return Point(x - val, y - val);
}

Point& Point::operator+=(int val)
{
    x += val;
    y += val;
    if (x < 0 || x > maxCoord + EPS || y < 0 || y > maxCoord + EPS)
        throw std::out_of_range("Point out of bounds after addition");
    return *this;
}

Point& Point::operator-=(int val)
{
    x -= val;
    y -= val;
    if (x < 0 || x > maxCoord + EPS || y < 0 || y > maxCoord + EPS)
        throw std::out_of_range("Point out of bounds after subtraction");
    return *this;
}

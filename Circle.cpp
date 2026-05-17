#include "Circle.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <stdexcept>

const double Circle::EPS = std::numeric_limits<double>::epsilon() * 1e7;

Circle::Circle() : center(0, 0), radius(0.0) {}

Circle::Circle(const Point& center, const Point& pointOnCircle)
    : center(center) 
{
    double dx = pointOnCircle.getX() - center.getX();
    double dy = pointOnCircle.getY() - center.getY();
    radius = std::hypot(dx, dy);
    if (radius <= EPS)
    {
        throw std::invalid_argument("Circle radius must be positive");
    }
}

Circle::Circle(double cx, double cy, double px, double py)
    : Circle(Point(cx, cy), Point(px, py)) {}

double Circle::getArea() const
{
    return M_PI * radius * radius;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * radius;
}

double Circle::getRadius() const
{
    return radius;
}

std::string Circle::toString() const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss << "Circle(center=" << center << ", radius=" << radius
       << ", area=" << getArea() << ", perimeter=" << getPerimeter() << ")";
    return ss.str();
}

void Circle::Read(std::istream& is)
{
    Point c, p;
    is >> c >> p;
    *this = Circle(c, p);
}

std::string Circle::toString(const Circle& c)
{
    return c.toString();
}

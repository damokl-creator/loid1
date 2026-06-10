#pragma once
#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
private:
    Point center;
    const double radius;
    static const double EPS;

public:
    Circle();
    Circle(const Point& center, const Point& pointOnCircle);
    Circle(const double cx, const double cy, const double px, const double py);

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const override;
    std::string toString() const override;
    void Read(std::istream& is) override;

    static std::string toString(const Circle& c);
};

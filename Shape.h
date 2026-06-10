#pragma once
#include <string>
#include <iostream>

class Shape
{
public:
    virtual std::string toString() const = 0;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual double getRadius() const = 0;
    virtual void Read(std::istream& is) = 0;
    virtual ~Shape() = default;

    friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
    friend std::istream& operator>>(std::istream& is, Shape& shape);
};

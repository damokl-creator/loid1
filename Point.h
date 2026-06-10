#pragma once
#include <iostream>
#include <limits>

class Point 
{
private:
    double x;
    double y;
    static const double maxCoord;
    static const double EPS;

public:
    Point(const double x = 0, const double y = 0);
    static void setMaxCoord(const double max);

    double getX() const;
    double getY() const;

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, const Point& p);

    Point operator+(const int val) const;
    Point operator-(const int val) const;
    Point& operator+=(const int val);
    Point& operator-=(const int val);
};

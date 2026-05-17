#pragma once
#include <iostream>
#include <limits>

class Point 
{
private:
    double x;
    double y;
    static double maxCoord;
    static const double EPS;

public:
    Point(double x = 0, double y = 0);
    static void setMaxCoord(double max);

    double getX() const;
    double getY() const;

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);

    Point operator+(int val) const;
    Point operator-(int val) const;
    Point& operator+=(int val);
    Point& operator-=(int val);
};

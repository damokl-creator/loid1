#include <gtest/gtest.h>
#include "Circle.h"
#include <sstream>

TEST(CircleTest, ConstructionAndGeometry)
{
    Circle c1(Point(0,0), Point(5,0));
    EXPECT_NEAR(c1.getRadius(), 5.0, 1e-6);
    EXPECT_NEAR(c1.getArea(), M_PI * 25, 1e-6);
    EXPECT_NEAR(c1.getPerimeter(), 2 * M_PI * 5, 1e-6);

    Circle c2(10, 10, 10, 20);
    EXPECT_NEAR(c2.getRadius(), 10.0, 1e-6);
}

TEST(CircleTest, ExceptionOnZeroRadius)
{
    EXPECT_THROW(Circle(Point(0,0), Point(0,0)), std::invalid_argument);
}

TEST(CircleTest, ReadMethod)
{
    Circle c;
    std::string input = "100 200 150 200";
    std::stringstream ss(input);
    ASSERT_NO_THROW(c.Read(ss));
    EXPECT_NEAR(c.getRadius(), 50.0, 1e-6);
    EXPECT_NEAR(c.getArea(), M_PI * 2500, 1e-6);
}

TEST(CircleTest, OutputMethod)
{
    Circle c(Point(0,0), Point(3,4));
    std::string str = c.toString();
    EXPECT_FALSE(str.empty());
    EXPECT_TRUE(str.find("Circle") != std::string::npos);
}

TEST(PointTest, BoundsChecking)
{
    Point::setMaxCoord(100);
    EXPECT_NO_THROW(Point(50, 50));
    EXPECT_THROW(Point(101, 50), std::out_of_range);
    EXPECT_THROW(Point(-1, 50), std::out_of_range);
}

TEST(PointTest, ArithmeticOperations)
{
    Point p(10, 20);
    Point q = p + 5;
    EXPECT_DOUBLE_EQ(q.getX(), 15);
    EXPECT_DOUBLE_EQ(q.getY(), 25);
    Point r = p - 3;
    EXPECT_DOUBLE_EQ(r.getX(), 7);
    EXPECT_DOUBLE_EQ(r.getY(), 17);
    p += 2;
    EXPECT_DOUBLE_EQ(p.getX(), 12);
    p -= 4;
    EXPECT_DOUBLE_EQ(p.getX(), 8);
}

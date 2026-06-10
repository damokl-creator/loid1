#include <gtest/gtest.h>
#include "Vector.h"
TEST(VectorTest, DefaultConstructor)
{
    Vector arr;
    EXPECT_EQ(arr.get_size(), 0);
    EXPECT_TRUE(arr.is_empty());
    EXPECT_EQ(arr.to_string(), "Empty");
}
TEST(VectorTest, InitializerList)
{
    Vector arr = {5, 15, 25};
    EXPECT_EQ(arr.get_size(), 3);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[2], 25);
}
TEST(VectorTest, CopyLogic)
{
    Vector arr1 = {1, 2, 3};
    Vector arr2 = arr1;
    EXPECT_EQ(arr2.to_string(), arr1.to_string());

    arr2[0] = 99;
    EXPECT_NE(arr2[0], arr1[0]); // Проверка независимости памяти
}
TEST(VectorTest, AssignmentOperator)
{
    Vector arr1 = {7, 8, 9};
    Vector arr2;
    arr2 = arr1;
    EXPECT_EQ(arr2.to_string(), "7 8 9");
}
TEST(VectorTest, InsertElement)
{
    Vector arr = {1, 2, 3};
    arr.insertAt(0, 100);
    EXPECT_EQ(arr.to_string(), "100 1 2 3");

    arr.insertAt(arr.get_size(), 200);
    EXPECT_EQ(arr.to_string(), "100 1 2 3 200");
}
TEST(VectorTest, RemoveElement)
{
    Vector arr = {10, 20, 30};
    arr.removeAt(1);
    EXPECT_EQ(arr.to_string(), "10 30");
    EXPECT_EQ(arr.get_size(), 2);
}
TEST(VectorTest, OutOfRangeErrors)
{
    Vector arr = {1};
    EXPECT_THROW(arr[5], std::out_of_range);
    EXPECT_THROW(arr.removeAt(5), std::out_of_range);
}tes
TEST(VectorTest, IndexOfSearch)
{
    Vector arr = {100, 200, 300};
    EXPECT_EQ(arr.indexOf(200), 1);
    EXPECT_EQ(arr.indexOf(999), -1);
}

#include "Shape.h"

std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
    os << shape.toString();
    return os;
}

std::istream& operator>>(std::istream& is, const Shape& shape)
{
    shape.Read(is);
    return is;
}

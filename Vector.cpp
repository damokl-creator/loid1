#include <iostream>
#include "Vector.h"
#include <sstream>

Vector::Vector() : m_elements(nullptr), m_count(0) {}
Vector::Vector(const std::initializer_list<int> items) : m_elements(nullptr), m_count(items.size())
{
    if (m_count > 0)
    {
        m_elements = new int[m_count];
        size_t idx = 0;
        for (const int &val : items)
        {
            m_elements[idx++] = val;
        }
    }
}
Vector::~Vector()
{
    delete[] m_elements;
}
Vector::Vector(const Vector &other) : m_elements(nullptr), m_count(other.m_count)
{
    if (m_count > 0)
    {
        m_elements = new int[m_count];
        for (size_t i = 0; i < m_count; ++i)
        {
            m_elements[i] = other.m_elements[i];
        }
    }
}
Vector::Vector(Vector &&other) : m_elements(nullptr), m_count(0)
{
    if (other.m_elements != nullptr)
    {
        // Выделяем новую память
        m_elements = new int[other.m_count];
        m_count = other.m_count;
        
        // Копируем данные из старого объекта в новый
        for (size_t i = 0; i < m_count; ++i)
        {
            m_elements[i] = other.m_elements[i];
        }
        
        // очищаем память
        delete[] other.m_elements;
        other.m_elements = nullptr;
        other.m_count = 0;
    }
}
std::string Vector::to_string() const
{
    if (is_empty())
        return "Empty";

    std::stringstream ss;
    for (size_t i = 0; i < m_count; ++i)
    {
        ss << m_elements[i];
        if (i < m_count - 1)
            ss << " ";
    }
    return ss.str();
}
size_t Vector::get_size() const
{
    return m_count;
}
bool Vector::is_empty() const
{
    return m_count == 0;
}
void Vector::insertAt(const size_t index, const int value)
{
    if (index > m_count)
        index = m_count;
    int *tempArray = new int[m_count + 1];
    for (size_t i = 0; i < index; ++i)
    {
        tempArray[i] = m_elements[i];
    }
    tempArray[index] = value;
    for (size_t i = index; i < m_count; ++i)
    {
        tempArray[i + 1] = m_elements[i];
    }
    delete[] m_elements;
    m_elements = tempArray;
    m_count++;
}
void Vector::removeAt(const size_t index)
{
    if (index >= m_count)
    {
        throw std::out_of_range("Выход за границы массива!");
    }
    int *tempArray = (m_count > 1) ? new int[m_count - 1] : nullptr;
    for (size_t i = 0; i < index; ++i)
    {
        tempArray[i] = m_elements[i];
    }
    for (size_t i = index + 1; i < m_count; ++i)
    {
        tempArray[i - 1] = m_elements[i];
    }
    delete[] m_elements;
    m_elements = tempArray;
    m_count--;
}
int Vector::indexOf(const int value) const
{
    for (size_t i = 0; i < m_count; ++i)
    {
        if (m_elements[i] == value)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}
Vector &Vector::operator=(const Vector &other)
{
    if (this != &other)
    {
        delete[] m_elements;
        m_count = other.m_count;
        m_elements = (m_count > 0) ? new int[m_count] : nullptr;
        for (size_t i = 0; i < m_count; ++i)
        {
            m_elements[i] = other.m_elements[i];
        }
    }
    return *this;
}
Vector &Vector::operator=(Vector &&other)
{
    if (this != &other)
    {
        delete[] m_elements;
        m_elements = other.m_elements;
        m_count = other.m_count;
        other.m_elements = nullptr;
        other.m_count = 0;
    }
    return *this;
}
int &Vector::operator[](const size_t index)
{
    if (index >= m_count)
    {
        throw std::out_of_range("Индекс выходит за пределы!");
    }
    return m_elements[index];
}
const int &Vector::operator[](const size_t index) const
{
    if (index >= m_count)
    {
        throw std::out_of_range("Индекс выходит за пределы!");
    }
    return m_elements[index];
}
std::ostream &operator<<(std::ostream &os, const Vector &arr)
{
    os << arr.to_string();
    return os;
}
std::istream &operator>>(std::istream &is, Vector &arr)
{
    int value = 0;
    if (is >> value)
    {
        arr.insertAt(arr.get_size(), value);
    }
    return is;
}

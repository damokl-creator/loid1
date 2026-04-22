//
// Created by D on 21.04.2026.
//

#include <iostream>
#include <cmath>
#include "shestiugolnik.h"
shestiugolnik::shestiugolnik(const Point centre, const double radi, const Point p) {
    this->centre = centre;
    this->radi = radi;
    this->p = p;
    if (centre == p)
    {
        std::cout << "Ошибка: Точка совпадает с центром!" << std::endl;
        exit(1);
    }
    if (radi <= 0)
    {
        std::cout << "Ошибка: Радиус не может быть не положительным." << std::endl;
        exit(1);
    }
    double check = sqrt(pow(p.getX()*p.getX(), 2) + pow(p.getY()*p.getY(), 2));
    if (check == radi)
    {
        std::cout << "Ошибка! Введённая точка не лежит на окружности!" << std::endl;
        exit(1);
    }
}

double shestiugolnik::getSide() const
{
    return radi;
}

double shestiugolnik::getPlo() const
{
    return 3 * sqrt(3) / 2 * pow(radi, 2);
}
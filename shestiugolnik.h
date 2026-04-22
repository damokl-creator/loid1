//
// Created by D on 21.04.2026.
//
#pragma once
#include "Point.h"
/**
 * @brief Класс шестиугольник
 */
class shestiugolnik
{

private:
    /**
     * @brief Центр шестиугольника
     */
    Point centre;
    /**
     * @brief Радиус шестиугольника
     */
    double radi;
    /**
     * @brief Вершина шестиугольника
     */
    Point p;

public:
    /**
     * @brief Конструктор
     * @param Centre - центр шестиугольника
     * @param Radi - радиус описанной окружности
     * @param p - вершина шестиугольника
     */
    shestiugolnik(Point centre, double radi, Point p);

    /**
     * @brief Расчёт длины стороны
     */
    double getSide() const;

    /**
     * @brief Расчёт площади шестиугольника
     */
    double getPlo() const;
};
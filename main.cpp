#include <iostream>
#include "shestiugolnik.h"
#include "Point.h"
/**
 * @brief Считывает значение, введенное с клавиатуры
 * @param report - строка информации
 * @return считанное значение
 */
double getValue(std::string report = "");
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    double cx = getValue("vvedite abcisu centra shestiugolnika: ");
    double cy = getValue("vvedite ordinatu centra shestiugolnika: ");
    double r = getValue("vvedite radius opisannoi okrujnosty: ");
    double px = getValue("vvedite abcisu tochki na okrujnosy: ");
    double py = getValue("vvedite ordinatu tochki na okrujnosy: ");
    Point mycentre(cx, cy);
    Point myp(px, py);
    shestiugolnik myShestiugolnik(mycentre, r, myp);
    double side = myShestiugolnik.getSide();
    std::cout << "storona = " << side << std::endl;
    std::cout << "ploshad: " << myShestiugolnik.getPlo() << std::endl;
    return 0;
}
double getValue(std::string report)
{
    std::cout << report;
    double value = 0;
    std::cin >> value;
    if (std::cin.fail())
    {
        std::cout << "warning, vvedeno nevernot znachenie!\n";
        exit(1);
    }
    return value;
}
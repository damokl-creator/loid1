#include <stdio.h>

/**
@breif Рассчитывает работу тока
@param I сила тока
@param U напряжение
@param t время
@return рассчитанное значение работы тока
*/
double get_current_operation (double I, double U, double t);

/**
* @brief Точка входа в программу
* @return возвращает 0, если программа выполнена корректно
*/
int main (void)
{
    double I;
    double U;

    int t = 20*60;
    printf("input current strength:");
    scanf("%lf", &I);
    printf("input voltage:");
    scanf("%lf", &U);

    printf("output current operation:%.3lf", get_current_operation(I, U, t));

    return 0;
}

double get_current_operation (double I, double U, double t)
{
    return I*U*t;
}

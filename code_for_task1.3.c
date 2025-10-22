#include <stdio.h>

/**
@breif Рассчитывает работу тока
@param x сила тока
@param y напряжение
@param z время
@return рассчитанное значение работы тока
*/
double get_current_strength (double x, double y, double z);

/**
* @brief Точка входа в программу
* @param x заданный пользователем значение массы мешка
* @return возвращает 0, если программа выполнена корректно
*/
int main (void)
{
    double I;
    double U;

    int t = 20*60;
    scanf("%lf", &I);
    scanf("%lf", &U);

    printf("%.3lf", get_current_strength(I, U, t));

    return 0;
}

double get_current_strength (double x, double y, double z)
{
    return x*y*z;
}

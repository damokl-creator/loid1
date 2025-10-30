#include <stdio.h>

/**
 * @brief переводит вес из грамм в унции
 * @param l вес в граммах
 * @return возвращает рассчитаный вес в унциях
 */
double get_weight_in_ounces (const double weight);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если код выполнен корректно
 */
int main(void)
{
    double x = 0;
    scanf("%lf", &x);
    printf("%.2lf", get_weight_in_ounces(x));

    return 0;
}

double get_weight_in_ounces (const double weight)
{
    return weight / 28.3;
}

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>


/*
*@brief Рассчитывает длину диогонали пярмоугольника
*@param x первая сторона прямоугольника
*@param y вторая сторона прямоугольника
*@return возвращает рассчитанную длинну диогонали
*/
double getdiog (const double x, const double y);
/*
*@brief Рассчитывает периметр пярмоугольника
*@param x первая сторона прямоугольника
*@param y вторая сторона прямоугольника
*@return возвращает рассчитанный периметр
*/
double getper(const double x, const double y);
/*
*@brief Рассчитывает площадь прямоугольника
*@param x первая сторона прямоугольника
*@param y вторая сторона прямоугольника
*@return возвращает рассчитанную площадь
*/
double getplo(const double x, const double y);
/**
@brief perimetr - периметр прямоугольника
@brief ploshad - площадь прямоугольника
@brief ploshad - длина диогонали прямоугольника
*/
enum {perimetr,ploshad, diog};
/*
*@brief Считывает значение, введенное с клавиатуру с проверкой ввода
*@return считанное значение
*/
double value();
/*
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkvalue(const double value);
/*
*@brief Точка входа в программу
*@param x выбранная пользователем сторона пярмоугольника
*@param y выбранная пользователем сторона прямоугольника
*@return возвращает 0, если программа выполнена корректно
*/
int main()
{
    printf("Введите длину первой стороны прямоугольника:");
    double x = value();
    checkvalue(x);
    printf("Введите длину второй стороны прямоугольника:");
    double y = value();
    checkvalue(y);
    printf("Выберите, что хотите посчитать: %d - периметр, %d - плоащдь, %d - длину диогонали\n",perimetr,ploshad,diog);
    int choice = (int) value();
    switch (choice)
    {
        case perimetr:
            printf("Периметр равен %.2lf\n",getper(x,y));
            break;
        case ploshad:
            printf("Площадь равна %.2lf\n",getplo(x,y));
            break;
        case diog:
            printf("Длина диогонали равна %.2lf\n", getdiog(x, y));
        default:
            printf("Вы ввели неверное значение!");
            abort();
    }

    return 0;

}
double value()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Ошибка! Введено неверное значение!\n");
        abort();
    }
    return value;
}
void checkvalue(const double value)
{
    if (value <= 0 + __DBL_EPSILON__ )
    {
        printf("Число должно быть положительным!\n");
        abort();
    }
}
double getdiog(const double x, const double y) {
    return sqrt((x * x) + (y * y));
}
double getper(const double x, const double y)
{
    return (x + y) * 2;
}
double getplo(const double x,const double y)
{
    return x * y;
}

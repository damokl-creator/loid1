#include <iostream>
#include <string>
#include <cstdlib>
#include "Vector.h"
using namespace std;
/**
 * @brief Нумерация объектов выбора
 */
enum Actions
{INSERT = 1,REMOVE,SEARCH};
/**
 * @brief Выводит ошибку и завершает работу программы
 * @param text - текст, выводимый на экран
 */
void ERROR(const string text)
{
    cerr << text << endl;
    exit(1);
}
/**
 * @brief Считывает значение, введенное с клавиатуры
 * @return считанное значение
 */
int get_choice()
{
    int number = 0;
    cin >> number;
    if (cin.fail())
    {
        ERROR("Ошибка ввода");
    }
    return number;
}
/**
 * @brief Точка входа в программу
 * @return Если программа выполнена корректно - 0, иначе 1
 */
int main()
{
    Vector collection;
    cout << "Укажите начальное количество элементов вектора: ";
    int n = get_choice();
    if (n < 0)
    {
        ERROR("Ошибка: количество элементов не может быть отрицательным.");
    }
    if (n > 0)
    {
        cout << "Введите " << n << " элементов вектора (через пробел или Enter): " << endl;
        for (size_t i = 0; i < static_cast<size_t>(n); ++i)
        {
            int val = get_choice();
            collection.insertAt(collection.get_size(), val);
        }
    }
    cout << "Изначальный вектор: " << collection << endl;
    cout << "Выберите действие с вектором: " << endl
         << INSERT << " - Вставить элемент" << endl
         << REMOVE << " - Удалить элемент" << endl
         << SEARCH << " - Найти элемент" << endl;
    cout << "Ваш выбор: ";
    int choice = get_choice();
    try
    {
        switch (choice)
        {
        case INSERT:
        {
            cout << "Введите индекс для вставки: ";
            int raw_index = get_choice();
            if (raw_index < 0)
                ERROR("Ошибка: индекс не может быть отрицательным.");
            cout << "Введите значение для вставки: ";
            int val = get_choice();
            collection.insertAt(static_cast<size_t>(raw_index), val);
            cout << "После добавления: " << collection << endl;
            break;
        }
        case REMOVE:
        {
            cout << "Введите индекс для удаления: ";
            int raw_index = get_choice();
            if (raw_index < 0)
                ERROR("Ошибка: индекс не может быть отрицательным.");
            collection.removeAt(static_cast<size_t>(raw_index));
            cout << "После удаления: " << collection << endl;
            break;
        }
        case SEARCH:
        {
            cout << "Введите число для поиска: ";
            int val = get_choice();
            int pos = collection.indexOf(val);
            if (pos != -1)
            {
                cout << "Элемент найден на индексе: " << pos << endl;
            }
            else
            {
                cout << "Элемент отсутствует в векторе." << endl;
            }
            break;
        }
        default:
            ERROR("Ошибка: Неверный выбор пункта меню.");
        }
    }
    catch (const exception &e)
    {
        cout << "Ошибка! " << e.what() << endl;
    }
    if (!collection.is_empty())
    {
        cout << endl
             << "Первый элемент равен: " << collection[0] << endl;
    }
    return 0;
}

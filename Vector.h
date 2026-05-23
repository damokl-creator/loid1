#pragma once
#include <iostream>
#include <initializer_list>
#include <string>

/*
 * @brief Класс Вектор
 */
class Vector
{
private:
    /**
     * @brief Указатель на массив элементов
     */
    int *m_elements;

    /**
     * @brief Количество элементов в коллекции
     */
    size_t m_count;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Vector();
    /**
     * @brief Конструктор со списком инициализации
     */
    Vector(const std::initializer_list<int> items);
    /**
     * @brief Конструктор копирования
     */
    Vector(const Vector &other);
    /**
     * @brief Конструктор перемещения
     */
    Vector(Vector &&other);
    /**
     * @brief Деструктор
     */
    ~Vector();
    /**
     * @brief Возвращает строку с содержимым коллекции
     */
    std::string to_string() const;
    /**
     * @brief Возвращает текущий размер
     */
    size_t get_size() const;
    /**
     * @brief Проверка коллекции на пустоту
     */
    bool is_empty() const;
    /**
     * @brief Вставка элемента по заданному индексу
     * @param index позиция
     * @param value новое значение
     */
    void insertAt(size_t index, const int value);
    /**
     * @brief Удаление элемента по заданному индексу
     * @param index позиция
     */
    void removeAt(const size_t index);
    /**
     * @brief Поиск элемента в коллекции
     * @param value искомое значение
     * @return индекс первого вхождения или -1, если не найден
     */
    int indexOf(const int value) const;
    /**
     * @brief Оператор присваивания (копирование)
     */
    Vector &operator=(const Vector &other);
    /**
     * @brief Оператор присваивания (перемещение)
     */
    Vector &operator=(Vector &&other);
    /**
     * @brief Переопределение оператора разыменования
     */
    int &operator[](const size_t index);
    /**
     * @brief Переопределение оператора разыменования
     */
    const int &operator[](const size_t index) const;
    /**
     * @brief Перегрузка оператора сдвига влево
     */
    friend std::ostream &operator<<(std::ostream &os, const Vector &arr);
    /**
     * @brief Перегрузка оператора сдвига вправо
     */
    friend std::istream &operator>>(std::istream &is, Vector &arr);
};

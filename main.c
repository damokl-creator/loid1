#include <stdio.h>
#include <stdlib.h>
#define scanf_s scanf

/**
 * @brief Считывает введённое с клавиатуры целое значение и проверяет на правильность ввода
 * @return введённое значение
 */
int Value(void);

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество его элементов)
 */
size_t getSize(char* message);

/**
 * @brief Считывает значения элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Выводит массив (его элементы)
 * @param arr массив
 * @param size размер массива
 */
void printArray(int* arr, const size_t size);

/**
 * @brief выводит на экран индексы элементов, кратных 3
 * @param arr массив
 * @param size размер массива
 */
void index3elements(int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Создаёт копию массива
 * @param arr массив
 * @param size размер массива
 * @return полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Меняет знак у последних К элементов массива
 * @param copyArr копия массива
 * @param size размер массива
 * @return Возвращает 1, если функция выполнена корректно, 0 - если введёное К превышает количество элементов массива
 */
int replaceLastKElements(int* copyArr, const size_t size);

/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int main(void)
{
    size_t size = getSize("Input size of an array:\n");
    int* arr = malloc(size* sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr,"Error");
        exit(1);
    }
    printf("Chose the method of filling the array:\n%d - by random\n%d - manually\n", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
        {
            case RANDOM:
                fillRandom(arr, size);
                break;
            case MANUAL:
                fillArray(arr, size);
                break;
            default:
                fprintf(stderr,"Error.");
                free(arr);
                exit(1);
        }
    printArray(arr, size);
    index3elements(arr, size);
    printf("\n");
    replaceLastKElements(arr, size);
    int* copyArr = copyArray(arr, size);
    free(copyArr);
    free(arr);
    return 0;
}

int Value(void)
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1){
        fprintf(stderr, "Input error");
        exit(1);
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        fprintf(stderr,"Input error");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Input %zu element of array:", i);
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    printf("Your array is:\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void index3elements(int* arr, const size_t size)
{
    int result = 0;
    printf("indices of elements that are multiples of 3: ");
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 3 == 0)
            {
                printf("%d ", i);
            }
    }
}

void fillRandom(int* arr, const size_t size)
{
    printf("diapozon start:\n");
    int start = Value();
    printf("diapozon end:\n");
    int end = Value();
    if (start >= end) {
        fprintf(stderr, "Error: end must be more than start\n");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int)*size);
    for (size_t i = 0; i<size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

int replaceLastKElements(int* copyArr, const size_t size) {
    printf("input k:\n");
    int k = Value();
    if (k > size) {
        printf("Error: k must be less than or equal to the number of array elements");
        return 0;
    }

    for (size_t i = (size - k); i < size; i++) {
        copyArr[i] = -1 *
            copyArr[i];
    }
    printf("Your new array is:\n");
    for (size_t j = 0; j < size; j++)
    {
        printf("%d ", copyArr[j]);
    }
    printf("\n");
    return 1;
}
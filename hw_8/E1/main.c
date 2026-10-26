#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Среднее арифметическое чисел
Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.

Формат входных данных
5 целых не нулевых чисел через пробел
Формат результата
Одно число в формате "%.3f"
Примеры
Входные данные
4 15 3 10 14
Результат работы
9.200
Входные данные
1 2 3 4 5
Результат работы
3.000
*/

#define SIZE 5U

double avg_array(const int32_t *array, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int32_t array[SIZE] = {0};

    for (size_t i = 0; i < SIZE; i++)
        if (scanf("%" SCNd32, array + i) != 1)
            return EXIT_FAILURE;
    
    printf("%.3f\n", avg_array(array, SIZE));
    
    return EXIT_SUCCESS;
}

double avg_array(const int32_t *array, size_t size)
{
    if (!array || !size)
        return 0.0;

    int64_t sum = 0;

    for (size_t i = 0; i < size; i++)
        sum += array[i];
    
    return (double)sum / (double)size;
}

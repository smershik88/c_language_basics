#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Сумма положительных элементов
Считать массив из 10 элементов и посчитать сумму положительных элементов массива.

Input format
10 целых чисел через пробел
Output format
Одно целое число - сумма положительных элементов массива
Examples
Input
4 -5 3 10 -4 -6 8 -10 1 0
Output
26
Input
1 -2 3 -4 5 -6 7 -8 9 0
Output
25
*/

#define SIZE 10U

bool read_array(int32_t *array, size_t n);
int64_t sum_positive_array(const int32_t *array, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int32_t array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;

    printf("%" PRId64, sum_positive_array(array, SIZE));
    
    return EXIT_SUCCESS;
}

bool read_array(int32_t *array,  size_t n)
{
    if (!array || !n)
        return false;

    for (size_t i = 0; i < n; i++)
    {
        if (scanf("%" SCNd32, array + i) != 1)
            return false;
    }
    
    return true;
}

int64_t sum_positive_array(const int32_t *array, size_t size)
{
    int64_t sum = 0;

    if (!array || !size)
        return sum;

    for (size_t i = 0; i < size; i++)
    {
        if (array[i] > 0)
            sum += array[i];
    }

    return sum;
}

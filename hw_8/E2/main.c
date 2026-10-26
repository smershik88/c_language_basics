#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Найти минимум
Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.

Input format
5 целых чисел через пробел
Output format
Одно единственное целое число
Examples
Input
4 15 3 10 14
Output
3
Input
1 2 3 4 -5
Output
-5
*/

#define SIZE 5U

bool read_array(int32_t *array, size_t n);
int32_t min_array(const int32_t *array, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int32_t array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;
    
    printf("%" PRId32 "\n", min_array(array, SIZE));
    
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

int32_t min_array(const int32_t *array, size_t size)
{
    int32_t min = INT32_MAX;

    if (!array || !size)
        return min;

    for (size_t i = 0; i < size; i++)
    {
        if (array[i] < min)
            min = array[i];
    }
    
    return min;
}

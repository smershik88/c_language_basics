#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Два максимума
Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.

Input format
10 целых чисел через пробел.
Output format
Сумма двух максимальных элементов.
Examples
Input
4 -5 3 10 -4 -6 8 -10 1 0
Output
18
Input
1 2 3 4 5 6 7 8 9 10
Output
19
*/

#define SIZE 10U

bool read_array(int32_t *array, size_t n);
int64_t sum_two_max_array(const int32_t *array, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int32_t array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;

    printf("%" PRId64, sum_two_max_array(array, SIZE));
    
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

int64_t sum_two_max_array(const int32_t *array, size_t size)
{
    int32_t max_1 = INT32_MIN,
            max_2 = INT32_MIN;

    if (!array || !size)
        return 0;

    for (size_t i = 0; i < size; i++)
    {
        if (array[i] > max_1)
        {
            max_2 = max_1;
            max_1 = array[i];
        }
        else if (array[i] > max_2)
        {
            max_2 = array[i];
        }
    }

    return max_2 + max_1;
}

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Максимум и минимум
Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.

Input format
10 целых чисел через пробел
Output format
4 целых числа через пробел: номер максимума, максимум, номер минимума, минимум.
Examples
Input
4 -5 3 10 -4 -6 8 -10 1 0
Output
4 10 8 -10
Input
1 2 3 4 5 6 7 8 9 10
Output
10 10 1 1
*/

#define SIZE 10U

typedef struct
{
    size_t index;
    int32_t value;
} array_element_t;

bool read_array(int32_t *array, size_t n);
array_element_t min_element_array(const int32_t *array, size_t size);
array_element_t max_element_array(const int32_t *array, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int32_t array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;
    
    array_element_t min = min_element_array(array, SIZE);
    array_element_t max = max_element_array(array, SIZE);

    printf("%zu %" PRId32 " %zu %" PRId32, max.index + 1, max.value, min.index + 1, min.value);
    
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

array_element_t min_element_array(const int32_t *array, size_t size)
{
    size_t index = 0;
    int32_t min = INT32_MAX;

    if (!array || !size)
        return (array_element_t){index, min};

    for (size_t i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            index = i;
            min = array[i];
        }
    }
    
    return (array_element_t){index, min};
}

array_element_t max_element_array(const int32_t *array, size_t size)
{
    size_t index = 0;
    int32_t max = INT32_MIN;

    if (!array || !size)
        return (array_element_t){index, max};
    
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            index = i;
            max = array[i];
        }
    }

    return (array_element_t){index, max};
}

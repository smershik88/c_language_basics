#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Инверсия каждой трети
Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.

Input format
12 целых чисел через пробел
Output format
12 целых чисел через пробел
Examples
Input
4 -5 3 10 -4 -6 8 -10 1 0 5 7
Output
10 3 -5 4 -10 8 -6 -4 7 5 0 1
Input
1 2 3 4 5 6 7 8 9 10 11 12
Output
4 3 2 1 8 7 6 5 12 11 10 9
*/

#define SIZE 12U

bool read_array(int32_t *array, size_t n);
void reverse_array(int32_t *array, size_t size);
void inverse_thirds_and_print_array(int32_t *array, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int32_t array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;

    inverse_thirds_and_print_array(array, SIZE);
    
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

void reverse_array(int32_t *array, size_t size)
{
    if (!array || !size)
        return;

    for (int32_t *left = array, *right = array + size - 1; left < right;)
    {
        const int32_t tmp = *left;
        *left++ = *right;
        *right-- = tmp;
    }
}

void inverse_thirds_and_print_array(int32_t *array, size_t size)
{
    if (!array || size % 3 != 0)
        return;

    const size_t third_size = size / 3;
    const size_t thirds_count = size / third_size;

    for (size_t i = 0; i < thirds_count; i++)
    {
        int32_t *start_ptr = array + third_size * i;
        reverse_array(start_ptr, third_size);
    }
    
    for (size_t i = 0; i < size; i++)
        printf("%" PRId32 " ", array[i]);
}

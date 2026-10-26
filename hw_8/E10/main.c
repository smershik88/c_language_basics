#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.

Input format
12 целых чисел через пробел
Output format
12 целых чисел через пробел
Examples
Input
4  -5   3  10  -4  -6   8 -10   1   0   5   7
Output
1   0   5   7   4  -5   3  10  -4  -6   8 -10
Input
1 2 3 4 5 6 7 8 9 10 11 12
Output
9 10 11 12 1 2 3 4 5 6 7 8
*/

#define SIZE 12U
#define ROR_N 4U

bool read_array(int32_t *array, size_t n);
void print_array(const int32_t *array, size_t n);
void reverse_array(int32_t *array, size_t size);
void ror_array(int32_t *array, size_t size, size_t n);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int32_t array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;

    ror_array(array, SIZE, ROR_N);
    print_array(array, SIZE);
    
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

void print_array(const int32_t *array, size_t n)
{
    if (!array || !n)
    return;

    for (size_t i = 0; i < n; i++)
        printf("%" PRId32 " ", array[i]);
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

void ror_array(int32_t *array, size_t size, size_t n)
{
    if (!array || !size)
    return;

    n %= size;
    if (n == 0)
        return;

    reverse_array(array, size);
    reverse_array(array, n);
    reverse_array(array + n, size - n);
}

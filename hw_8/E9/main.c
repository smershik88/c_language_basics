#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Циклический сдвиг массива вправо
Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.

Input format
10 целых чисел через пробел
Output format
10 целых чисел через пробел сдвинутых вправо на 1 элемент циклически
Examples
Input
4   -5   3  10  -4  -6  8  -10  1  0
Output
0   4   -5   3  10  -4  -6  8  -10  1
Input
1 2 3 4 5 6 7 8 9 10
Output
10 1 2 3 4 5 6 7 8 9
*/

#define SIZE 10U

bool read_array(int32_t *array, size_t n);
void print_array(const int32_t *array, size_t n);
void swap(int32_t *a, int32_t *b);
void ror1_array(int32_t *array, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int32_t array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;

    ror1_array(array, SIZE);
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

void swap(int32_t *a, int32_t *b)
{
    if (!a || !b)
        return;

    int32_t tmp = *a;
    *a = *b;
    *b = tmp;
}

void ror1_array(int32_t *array, size_t size)
{
    if (!array || !size)
    return;

    int32_t last = array[size - 1];

    for (size_t i = size - 1; i > 0; i--)
        swap(array + i, array + (i - 1));

    array[0] = last;
}

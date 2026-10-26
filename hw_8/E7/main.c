#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Инверсия половинок
Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива. Необходимо изменить считанный массив и напечатать его одним циклом.

Input format
10 целых элементов массива через пробел.
Output format
10 целых элементов массива через пробел.
Examples
Input
4 -5 3 10 -4 -6 8 -10 1 0
Output
-4 10 3 -5 4 0 1 -10 8 -6
Input
1 2 3 4 5 6 7 8 9 10
Output
5 4 3 2 1 10 9 8 7 6
*/

#define SIZE 10U

bool read_array(int32_t *array, size_t n);
void swap(int32_t *a, int32_t *b);
void print_inversed_halfs_array(int32_t *array, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int32_t array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;

    print_inversed_halfs_array(array, SIZE);
    
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

void swap(int32_t *a, int32_t *b)
{
    if (!a || !b)
        return;

    int32_t tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_inversed_halfs_array(int32_t *array, size_t size)
{
    const size_t middle = size / 2;
    const size_t right_half_start = middle + (size % 2);
    
    for (size_t i = 0; i < size; i++)
    {
        if (i < middle)
        {
            const size_t j = middle - 1 - i;

            if (i < j)
                swap(array + i, array + j);
        }
        else if (i >= right_half_start)
        {
            const size_t j = right_half_start + (size - 1 - i);

            if (i < j)
                swap(array + i, array + j);
        }
        
        printf("%" PRId32 " ", array[i]);
    }
}

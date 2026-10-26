#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Только один раз
Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран.

Input format
10 целых чисел через пробел
Output format
Элементы которые встречаются только один раз через пробел
Examples
Input
5   -4   0  1   4  -3  -3  3  0  2
Output
5  -4  1  4  3  2
*/

#define SIZE 10U

bool read_array(int32_t *array, size_t n);
void print_array(const int32_t *array, size_t n);
size_t count_array(const int32_t *array, size_t size, int32_t n);
size_t copy_unique_array(const int32_t *src_array, size_t src_array_size,
    int32_t* dest_array, size_t dest_array_size
);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    int32_t array[SIZE] = {0};
    int32_t unique_array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;
    
    size_t unique_array_size = copy_unique_array(array, SIZE,
        unique_array, SIZE
    );
    print_array(unique_array, unique_array_size);
    
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

size_t count_array(const int32_t *array, size_t size, int32_t n)
{
    if (!array || !size)
        return 0 ;

    size_t count = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == n)
            count++;
    }
    
    return count;
}

size_t copy_unique_array(const int32_t *src_array, size_t src_array_size,
                         int32_t *dest_array, size_t dest_array_size)
{
    if (src_array == dest_array || src_array_size < dest_array_size ||
        !src_array || !dest_array ||
        !src_array_size || !dest_array_size
    )
    {
        return 0;
    }

    size_t count = 0;

    for (size_t i = 0; i < src_array_size; i++)
    {
        if (count_array(src_array, src_array_size, src_array[i]) == 1)
            dest_array[count++] = src_array[i];
    }

    return count;
}

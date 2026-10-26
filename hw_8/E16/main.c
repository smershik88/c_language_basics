#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1.

Input format
10 целых числе через пробел
Output format
Одно число, которое встречается чаще других.
Examples
Input
4  1  2  1  11  2  34  11  0  11
Output
11
*/

#define SIZE 10U

bool read_array(int32_t *array, size_t n);
void print_array(const int32_t *array, size_t n);
int cmp_int32_by_asc(const void *pa, const void *pb);
int32_t most_frequent_array(const int32_t *array, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    int32_t array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;
    
    printf("%" PRId32, most_frequent_array(array, SIZE));
    
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

int cmp_int32_by_asc(const void *pa, const void *pb)
{   
    int32_t a = *(const int32_t*)pa,
            b = *(const int32_t*)pb;

    return (a > b) - (a < b);
}

int32_t most_frequent_array(const int32_t *array, size_t size)
{
    if (!array || !size)
        return INT32_MIN;

    int32_t *sorted_array = malloc(size * sizeof array[0]);
    if (!sorted_array)
        return INT32_MIN;

    memcpy(sorted_array, array, size * sizeof array[0]);
    qsort(sorted_array, size,
        sizeof array[0], cmp_int32_by_asc
    );

    size_t  start_group_index = 0,
            max_group_length = 1;
    int32_t most_frequent = INT32_MIN;

    while (start_group_index < size)
    {
        size_t current_index = start_group_index + 1;

        while (current_index < size &&
            sorted_array[current_index] == sorted_array[start_group_index]
        )
        {
            current_index++;
        }

        const size_t group_length = current_index - start_group_index;

        if (group_length > max_group_length)
        {
            max_group_length = group_length;
            most_frequent = sorted_array[start_group_index];
        }

        start_group_index = current_index;
    }
    
    free(sorted_array);
    return most_frequent;
}

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
По убыванию и по возрастанию
Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.

Input format
10 целых чисел через пробел
Output format
Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию.
Examples
Input
14  25  13  30  76  58  32  11  41  97
Output
13  14  25  30  76  97  58  41  32  11
Input
5 4 3 2 1 6 7 8 9 10
Output
1 2 3 4 5 10 9 8 7 6
*/

#define SIZE 10U

bool read_array(int32_t *array, size_t n);
void print_array(const int32_t *array, size_t n);
int cmp_int32_by_asc(const void *pa, const void *pb);
int cmp_int32_by_desc(const void *pa, const void *pb);
void sort_halfs_asc_desc_array(int32_t *array, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    int32_t array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;

    sort_halfs_asc_desc_array(array, SIZE);
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

int cmp_int32_by_asc(const void *pa, const void *pb)
{   
    int32_t a = *(const int32_t*)pa,
            b = *(const int32_t*)pb;

    return (a > b) - (a < b);
}

int cmp_int32_by_desc(const void *pa, const void *pb)
{   
    int32_t a = *(const int32_t*)pa,
            b = *(const int32_t*)pb;

    return (b > a) - (b < a);
}

void sort_halfs_asc_desc_array(int32_t *array, size_t size)
{
    if (!array || !size)
        return;

    int32_t *first_half_start = array,
            *second_half_start = array + SIZE / 2;
    size_t  fisrt_half_size = SIZE / 2,
            second_half_size = SIZE / 2 + SIZE % 2,
            size_of_element = sizeof array[0];

    qsort(first_half_start,
        fisrt_half_size,
        size_of_element,
        cmp_int32_by_asc
    );
    qsort(second_half_start,
        second_half_size,
        size_of_element,
        cmp_int32_by_desc
    );
}

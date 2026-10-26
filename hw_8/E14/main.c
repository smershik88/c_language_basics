#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Более одного раза
Считать массив из 10 элементов и выделить в другой массив все числа, которые встречаются более одного раза. В результирующем массиве эти числа не должны повторяться.

Input format
10 целых чисел через пробел
Output format
Целые числа через пробел, которые встречаются более одного раза в исходном массиве.
Examples
Input
4 1 2 1 11 2 34 8 9 10
Output
1 2
Input
1 2 3 4 5 1 2 3 4 5
Output
1 2 3 4 5
Input
1 1 1 1 1 1 1 1 1 1
Output
1
*/

#define SIZE 10U

bool read_array(int32_t *array, size_t n);
void print_array(const int32_t *array, size_t n);
int cmp_int32_by_asc(const void *pa, const void *pb);
size_t copy_dups_array(const int32_t *src_array, size_t src_array_size,
    int32_t* dest_array, size_t dest_array_size
);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    int32_t array[SIZE] = {0};
    int32_t result_array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;
    
    size_t result_size = copy_dups_array(array, SIZE,
        result_array, SIZE
    );

    print_array(result_array, result_size);
    
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

size_t copy_dups_array(const int32_t *src_array, size_t src_array_size,
    int32_t* dest_array, size_t dest_array_size
)
{
    if (src_array == dest_array || src_array_size < dest_array_size ||
        !src_array || !dest_array ||
        !src_array_size || !dest_array_size
    )
    {
        return 0;
    }

    int32_t *buffer = malloc(src_array_size * sizeof src_array[0]);
    if (!buffer)
        return 0;

    memcpy(buffer, src_array, src_array_size * sizeof src_array[0]);
    qsort(buffer, src_array_size,
        sizeof src_array[0], cmp_int32_by_asc
    );

    size_t count = 0;
    size_t start_group_index = 0;

    while (start_group_index < src_array_size)
    {
        size_t current_index = start_group_index + 1;

        while (current_index < src_array_size &&
            buffer[current_index] == buffer[start_group_index]
        )
        {
            current_index++;
        }

        const size_t group_length = current_index - start_group_index;

        if (group_length > 1)
            dest_array[count++] = buffer[start_group_index];

        start_group_index = current_index;
    }
    
    free(buffer);
    return count;
}

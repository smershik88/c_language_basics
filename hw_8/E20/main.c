#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Переставить цифры
Переставить цифры в числе так, что бы получилось максимальное число.

Input format
Одно целое не отрицательное число
Output format
Целое не отрицательное число
Examples
Input
1229
Output
9221
Input
19
Output
91
*/

size_t get_digits_array(uint32_t n, uint8_t **dest_array);
int cmp_uint8_by_desc(const void *pa, const void *pb);
uint64_t get_max_number(const uint8_t* digits_array, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    uint32_t n = 0;
    uint8_t *digits_array = NULL;

    if (scanf("%" SCNu32, &n) != 1)
        return EXIT_FAILURE;
    
    size_t count = get_digits_array(n, &digits_array);
    printf("%" PRIu64, get_max_number(digits_array, count));

    free(digits_array);
    return EXIT_SUCCESS;
}

size_t get_digits_array(uint32_t n, uint8_t **dest_array)
{
    if (dest_array == NULL || *dest_array != NULL)
        return 0;

    size_t digits_count = 0;
    for (uint32_t n_tmp = n; n_tmp != 0; n_tmp /= 10)
        digits_count++;

    if (digits_count == 0)
        return 0;

    *dest_array = malloc(digits_count * sizeof(uint8_t));
    if (*dest_array == NULL)
        return 0;
    
    for(size_t i = 0; n != 0;)
    {
        const uint8_t digit = (uint8_t)(n % 10);
        n /= 10;
        (*dest_array)[(digits_count - 1) - i++] = digit;
    }

    return digits_count;
}

int cmp_uint8_by_desc(const void *pa, const void *pb)
{   
    uint8_t a = *(const uint8_t*)pa,
            b = *(const uint8_t*)pb;

    return (b > a) - (b < a);
}

uint64_t get_max_number(const uint8_t *digits_array, size_t size)
{
    if (!digits_array || !size)
        return 0;

    uint8_t *buffer = malloc(size * sizeof digits_array[0]);
    if (!buffer)
        return 0;

    memcpy(buffer, digits_array, size * sizeof digits_array[0]);
    qsort(buffer, size,
        sizeof digits_array[0], cmp_uint8_by_desc
    );

    uint64_t max_number = 0;

    for (size_t i = 0; i < size; i++)
        max_number = max_number * 10 + buffer[i];

    free(buffer);
    return max_number;
}

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Цифры по порядку
Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N.

Input format
Одно натуральное число N
Output format
Цифры через пробел
Examples
Input
54412
Output
5 4 4 1 2
*/

void print_array(const uint8_t *array, size_t n);
size_t get_digits_array(uint32_t n, uint8_t **dest_array);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    uint32_t n = 0;
    uint8_t *digits_array = NULL;

    if (scanf("%" SCNu32, &n) != 1)
        return EXIT_FAILURE;
    
    size_t count = get_digits_array(n, &digits_array);
    print_array(digits_array, count);

    free(digits_array);
    return EXIT_SUCCESS;
}

void print_array(const uint8_t *array, size_t n)
{
    if (!array || !n)
    return;

    for (size_t i = 0; i < n; i++)
        printf("%" PRIu8 " ", array[i]);
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

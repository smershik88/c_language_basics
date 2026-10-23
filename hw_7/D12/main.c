#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Монотонная последовательность
Дана монотонная последовательность, в которой каждое натуральное число k встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,…
Выведите первые n членов этой последовательности.

Input format
Натуральное число.
Output format
Последовательность целых чисел.
Examples
Input
11
Output
1 2 2 3 3 3 4 4 4 4 5
*/

uint32_t print_monotonic_seq(uint32_t k, uint32_t n);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    scanf("%" SCNu32, &n);
    print_monotonic_seq(1, n);
    
    return EXIT_SUCCESS;
}

uint32_t print_monotonic_seq(uint32_t k, uint32_t n)
{
    if(n <= 0)
        return 0;

    uint32_t quantity_to_print = k < n ? k : n;

    for (size_t i = 0; i < quantity_to_print; i++)
    {
        printf("%" PRIu32 " ", k);
    }

    uint32_t remaining_quantity = print_monotonic_seq(k + 1, n - quantity_to_print);

    return quantity_to_print + remaining_quantity;
}

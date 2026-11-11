#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
В обратном порядке
Дано целое не отрицательное число N. Выведите все его цифры по одной, в обратном порядке, разделяя
их пробелами или новыми строками.

Input format
Одно не отрицательное целое число
Output format
Последовательность цифр введенного числа в обратном порядке через пробел
Examples
Input
15
Output
5 1
Input
54321
Output
1 2 3 4 5
*/

#define DEC_BASE 10

void print_digits_rev(uint32_t n);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    if (scanf("%" SCNu32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    print_digits_rev(n);

    return EXIT_SUCCESS;
}

void print_digits_rev(uint32_t n)
{
    if (n < DEC_BASE)
    {
        printf("%" PRIu32, n);
        return;
    }

    printf("%" PRIu32 " ", n % DEC_BASE);
    print_digits_rev(n / DEC_BASE);
}

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
В обратном порядке
Дано целое не отрицательное число N. Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами или новыми строками.

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

void print_digits_rev(uint32_t n);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    scanf("%" SCNu32, &n);
    print_digits_rev(n);
    
    return EXIT_SUCCESS;
}

void print_digits_rev(uint32_t n)
{
    if (n < 10)
    {
        printf("%" PRIu32, n);
        return;
    }
    
    printf("%" PRIu32 " ", n % 10);
    print_digits_rev(n / 10);
}

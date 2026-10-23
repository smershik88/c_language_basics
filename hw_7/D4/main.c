#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
В прямом порядке
Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками. Необходимо реализовать рекурсивную функцию.
void print_num(int num)

Input format
Одно целое неотрицательное число
Output format
Все цифры числа через пробел в прямом порядке.
Examples
Input
15
Output
1 5
Input
54321
Output
5 4 3 2 1
*/

void print_digits(uint32_t n);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    scanf("%" SCNu32, &n);
    print_digits(n);
    
    return EXIT_SUCCESS;
}

void print_digits(uint32_t n)
{
    if (n < 10)
    {
        printf("%" PRIu32 " ", n);
        return;
    }
    
    print_digits(n / 10);
    printf("%" PRIu32 " ", n % 10);
}

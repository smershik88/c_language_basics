#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
От 1 до N
Составить рекурсивную функцию, печать всех чисел от N до 1.

Input format
Одно натуральное число
Output format
Последовательность целых чисел от введенного числа до 1, через пробел.
Examples
Input
5
Output
5 4 3 2 1
*/

void print_reversed(uint32_t n);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    scanf("%" SCNu32, &n);
    print_reversed(n);
    
    return EXIT_SUCCESS;
}

void print_reversed(uint32_t n)
{
    if (n == 1)
    {
        puts("1");
        return;
    }

    printf("%" PRIu32 " ", n);

    print_reversed(n - 1);
}

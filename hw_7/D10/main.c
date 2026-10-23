#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Проверка на простоту
Дано натуральное число n ≥ 1. Проверьте, является ли оно простым. Программа должна вывести слово YES, если число простое или NO в противном случае. Необходимо составить рекурсивную функцию и использовать ее.
int is_prime(int n, int delitel)

Input format
Натуральное число
Output format
YES или NO
Examples
Input
11
Output
YES
Input
12
Output
NO
Input
73
Output
YES
*/

bool is_prime(uint32_t n, uint32_t divisor);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    scanf("%" SCNu32, &n);
    puts(is_prime(n, 2) ? "YES" : "NO");
    
    return EXIT_SUCCESS;
}

bool is_prime(uint32_t n, uint32_t divisor)
{
    if (n <= 1)
        return false;
    if (divisor == n)
        return true;
    if (divisor * divisor == n)
        return n % divisor;

    return n % divisor && is_prime(n, divisor + 1);
}

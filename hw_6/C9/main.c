#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Факториал
Составить функцию вычисления N!. Использовать ее при вычислении факториала int factorial(int n)

Input format
Целое положительное число не больше 20
Output format
Целое положительное число
Examples
Input
5
Output
120
*/

uint64_t factorial(uint32_t n);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    uint32_t n = 0;

    scanf("%" SCNu32, &n);

    if (n > 20)
        return EXIT_FAILURE;
    
    printf("%" PRId64, factorial(n));

    return EXIT_SUCCESS;
}

uint64_t factorial(uint32_t n)
{
    if (n <= 1)
        return 1;
    else return n * factorial(n - 1);
}
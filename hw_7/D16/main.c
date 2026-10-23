#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Точная степень двойки
Написать логическую рекурсивную функцию и используя ее определить является ли введенное натуральное число точной степенью двойки.
int is2pow(int n)

Формат входных данных
Одно натуральное число.
Формат результата
YES или NO
Примеры
Входные данные
8
Результат работы
YES
Входные данные
7
Результат работы
NO
*/

bool is2pow(uint32_t n);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    scanf("%" SCNu32, &n);

    puts(is2pow(n) ? "YES" : "NO");
    
    return EXIT_SUCCESS;
}

bool is2pow(uint32_t n)
{
    if (n == 0)
        return false;
        
    if (n == 1)
        return true;

    return (n % 2 == 0) && is2pow(n >> 1U);
}

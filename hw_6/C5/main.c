#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.

Формат входных данных
Одно целое положительное число N
Формат результата
Целое число - сумма чисел от 1 до N
Примеры
Входные данные
100
Результат работы
5050
*/

uint64_t sum_uint32(uint32_t x);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    uint32_t n = 0;

    scanf("%" SCNu32, &n);

    printf("%" PRIu64, sum_uint32(n));
    
    return EXIT_SUCCESS;
}

uint64_t sum_uint32(uint32_t x)
{
    uint64_t result = 0;
    for (uint32_t i = 1; i <= x; i++)
        result += i;
    return result;
}
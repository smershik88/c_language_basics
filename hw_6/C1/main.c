#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Модуль числа
Составить функцию, модуль числа и привести пример ее использования.

Формат входных данных
Целое число
Формат результата
Целое не отрицательное число
Примеры
Входные данные
-100
Результат работы
100
*/

uint32_t abs_32(int32_t n);

int main(int argc, char* argv[])
{
    int32_t n = 0;

    scanf("%" SCNd32, &n);
    printf("%" PRIu32 "\n", abs_32(n));
    
    return EXIT_SUCCESS;
}

uint32_t abs_32(int32_t n)
{
    return n < 0 ? (uint32_t)-n : (uint32_t)n;
}
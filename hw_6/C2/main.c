#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Возвести в степень
Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования.

Формат входных данных
Два целых числа: N по модулю не превосходящих 1000 и P ≥ 0
Формат результата
Одно целое число
Примеры
Входные данные
8 3
Результат работы
512
Входные данные
-5 2
Результат работы
25
*/

uint32_t abs_32(int32_t n);
int32_t power(int32_t n, int8_t p);

int main(int argc, char* argv[])
{
    int32_t n = 0;
    int8_t p = 0;

    scanf("%" SCNd32 " %" SCNd8, &n, &p);
    
    if (abs_32(n) > 100 || p < 0)
        return EXIT_FAILURE;

    printf("%" PRId32 "\n", power(n, p));
    
    return EXIT_SUCCESS;
}

uint32_t abs_32(int32_t n)
{
    return n < 0 ? (uint32_t)-n : (uint32_t)n;
}

int32_t power(int32_t n, int8_t p)
{
    int32_t result = 1;

    if (p == 0)
        return result;
        
    while(p--)
    {
        result *= n;
    }

    return result;
}
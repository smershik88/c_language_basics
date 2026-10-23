#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Возвести в степень
Написать рекурсивную функцию возведения целого числа n в степень p.
int recurs_power(int n, int p)
Используя данную функцию, решить задачу.

Формат входных данных
Два целых числа -100 ≤ n ≤ 100 и 0 ≤ p ≤ 100
Формат результата
Одно целое число n в степени p
Примеры
Входные данные
2 3
Результат работы
8
Входные данные
3 4
Результат работы
81
*/

int64_t recurs_power(int8_t n, uint8_t p);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int8_t n = 0;
    uint8_t p = 0;

    scanf("%" SCNd8 " %" SCNu8, &n, &p);

    printf("%" PRId64, recurs_power(n, p));
    
    return EXIT_SUCCESS;
}

int64_t recurs_power(int8_t n, uint8_t p)
{
    if (p == 0)
        return 1;

    if (p == 1)
        return n;

    return n * recurs_power(n, p - 1);
}

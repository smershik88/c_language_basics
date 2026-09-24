#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Наименьшее из пяти чисел
Ввести пять чисел и найти  наименьшее из них.

Формат входных данных
Пять целых чисел
Формат результата
Одно целое число
Примеры
Входные данные
4    15    9    56    4
Результат работы
4
*/

static int32_t min_5_int32(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e);

int main(int argc, char* argv[])
{
    int32_t a = 0,
            b = 0,
            c = 0,
            d = 0,
            e = 0;
    
    // printf("Input five integer numbers: ");
    scanf("%" SCNd32 " %" SCNd32" %" SCNd32" %" SCNd32" %" SCNd32, &a, &b, &c, &d, &e);

    printf("%" PRId32 "\n", min_5_int32(a, b, c, d, e));

    return EXIT_SUCCESS;
}

static int32_t min_5_int32(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e)
{
    int32_t min = a;

    if (b <= min)
        min = b;
    if (c <= min)
        min = c;
    if (d <= min)
        min = d;
    if (e <= min)
        min = e;

    return min;
}

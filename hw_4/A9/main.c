#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Наибольшее из пяти чисел
Ввести пять чисел и найти наибольшее из них.

Формат входных данных
Пять целых чисел разделенных пробелом

Формат результата
Одно целое число

Примеры
Входные данные
4    15    9    56    4
Результат работы
56
*/

static int32_t max_5_int32(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e);

int main(int argc, char* argv[])
{
    int32_t a = 0,
            b = 0,
            c = 0,
            d = 0,
            e = 0;
    
    // printf("Input five integer numbers: ");
    scanf("%" SCNd32 " %" SCNd32" %" SCNd32" %" SCNd32" %" SCNd32, &a, &b, &c, &d, &e);

    printf("%" PRId32 "\n", max_5_int32(a, b, c, d, e));

    return EXIT_SUCCESS;
}

static int32_t max_5_int32(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e)
{
    int32_t max = a;

    if (b >= max)
        max = b;
    if (c >= max)
        max = c;
    if (d >= max)
        max = d;
    if (e >= max)
        max = e;

    return max;
}

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Разность двух чисел
Ввести два числа и найти их разность.

Формат входных данных
Два целых числа

Формат результата
Ответ - одно целое число

Примеры
Входные данные
4 5
Результат работы
-1
Входные данные
100 49
Результат работы
51
*/

int main(int argc, char* argv[])
{
    int32_t a = 0,
            b = 0,
            diff = 0;

    // printf("Input two integer numbers: ");
    scanf("%" SCNd32 " %" SCNd32, &a, &b);

    diff = a - b;

    printf("%" PRId32 "\n", diff);

    return EXIT_SUCCESS;
}
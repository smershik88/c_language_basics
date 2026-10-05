#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Среднее арифметическое чисел
Написать функцию, которая возвращает среднее арифметическое двух переданных ей аргументов (параметров). int middle(int a, int b)

Формат входных данных
Два целых не отрицательных числа
Формат результата
Одно целое число
Примеры
Входные данные
5 7
Результат работы
6
Входные данные
10 20
Результат работы
15
*/

int32_t middle(int32_t a, int32_t b);

int main(int argc, char* argv[])
{
    int32_t a = 0,
            b = 0;

    scanf("%" SCNd32 " %" SCNd32, &a, &b);
    
    if (a < 0 || b < 0)
        return EXIT_FAILURE;

    printf("%" PRId32 "\n", middle(a, b));
    
    return EXIT_SUCCESS;
}

int32_t middle(int32_t a, int32_t b)
{
    return (a + b) / 2;
}
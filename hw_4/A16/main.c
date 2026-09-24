#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
В порядке возрастания
Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.

Формат входных данных
Три целых числа
Формат результата
Одно слово YES или NO
Примеры
Входные данные
4 5 17
Результат работы
YES
*/

int main(int argc, char* argv[])
{
    int32_t a = 0,
            b = 0,
            c = 0;

    // printf("Input three integer numbers: ");
    scanf("%" SCNd32 " %" SCNd32 " %" SCNd32, &a, &b, &c);

    printf("%s\n", a < b && b < c ? "YES" : "NO");

    return EXIT_SUCCESS;
}
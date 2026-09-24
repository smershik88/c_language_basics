#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Above, less, equal
Ввести два числа. Если первое число больше второго, то программа печатает слово Above. Если первое число меньше второго, то программа печатает слово Less. А если числа равны, программа напечатает сообщение Equal.

Формат входных данных
Два целых числа
Формат результата
Одно единственное слово: Above, Less, Equal
Примеры
Входные данные
24 24
Результат работы
Equal
Входные данные
100 0
Результат работы
Above
*/

int main(int argc, char* argv[])
{
    int32_t a = 0,
        b = 0;

    // printf("Input two integer numbers: ");
    scanf("%" SCNd32 " %" SCNd32, &a, &b);

    printf("%s\n",
        a < b ? "Less" : (a > b ? "Above" : "Equal")
    );

    return EXIT_SUCCESS;
}
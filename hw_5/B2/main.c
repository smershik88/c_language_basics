#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Квадраты чисел
Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b.

Формат входных данных
Два целых числа по модулю не больше 100
Формат результата
Квадраты чисел от a до b.
Примеры
Входные данные
4 5
Результат работы
16 25
Входные данные
1 5
Результат работы
1 4 9 16 25
*/

#define ABS_MAX 100

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int8_t a = 0, b = 0;

    // printf("Enter two integers a and b whose absolute value does not exceed 100 and a <= b: ");
    if (scanf("%" SCNd8 " %" SCNd8, &a, &b) != 2)
    {
        return EXIT_FAILURE;
    }

    if (a > b || abs(a) > ABS_MAX || abs(b) > ABS_MAX)
    {
        return EXIT_FAILURE;
    }

    for (; a <= b; a++)
    {
        printf("%" PRIu16 " ", a * a);
    }

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

/*
Среднее арифметическое трех чисел
Ввести три числа, найти их среднее арифметическое.

Формат входных данных
Три целых числа

Формат результата
Вещественное число в формате %.2f

Примеры
Входные данные
4 5 7
Результат работы
5.33
Входные данные
1 2 3
Результат работы
2.00
*/

#define NUMBER_OF_NUMBERS 3

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int    a = 0, b = 0, c = 0;
    double avg = 0;

    // printf("Input three integer numbers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3)
    {
        return EXIT_FAILURE;
    }

    avg = (a + b + c) / (double)NUMBER_OF_NUMBERS;

    printf("%.2f\n", avg);

    return EXIT_SUCCESS;
}

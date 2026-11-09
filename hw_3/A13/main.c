#include <stdio.h>
#include <stdlib.h>

/*
Произведение цифр
На вход подается произвольное трехзначное число, напечать произведение цифр

Формат входных данных
Трехзначное целое положительное число
Формат результата
Одно целое число
Примеры
Входные данные
435
Результат работы
60
Входные данные
102
Результат работы
0
*/

#define DEC_BASE 10

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int number      = 0;
    int digits_prod = 1;

    // printf("Input integer number: ");
    if (scanf("%d", &number) != 1)
    {
        return EXIT_FAILURE;
    }

    number = abs(number);

    while (number)
    {
        digits_prod *= number % DEC_BASE;
        number = number / DEC_BASE;
    }

    printf("%d\n", digits_prod);

    return EXIT_SUCCESS;
}

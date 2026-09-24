#include <stdio.h>
#include <stdlib.h>

/*
Сумма цифр
На вход подается произвольное трехзначное число, напечать сумму цифр

Формат входных данных
Трехзначное целое положительное число
Формат результата
Одно целое число
Примеры
Входные данные
435
Результат работы
12
Входные данные
100
Результат работы
1
*/

int main(int argc, char* argv[])
{
    int number = 0,
        digits_sum = 0;

    // printf("Input integer number: ");
    scanf("%d", &number);

    number = abs(number);

    while (number)
    {
        digits_sum += number % 10;
        number = number / 10;
    }

    printf("%d\n", digits_sum);

    return EXIT_SUCCESS;
}
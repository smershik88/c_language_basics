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

int main(int argc, char* argv[])
{
    int number = 0;
    int digits_prod = 1;

    // printf("Input integer number: ");
    scanf("%d", &number);

    number = abs(number);

    while (number)
    {
        digits_prod *= number % 10;
        number = number / 10;
    }

    printf("%d\n", digits_prod);

    return EXIT_SUCCESS;
}
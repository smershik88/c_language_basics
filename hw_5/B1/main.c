#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Квадраты и кубы
Ввести натуральное число вывести квадраты и кубы всех чисел от 1 до этого числа. Число не превосходит 100.
Формат входных данных
Одно целое число не превосходящее 100
Формат результата
Для каждого из чисел от 1 до введенного числа напечатать квадрат числа и его куб.
Примеры
Входные данные
3
Результат работы
1 1 1
2 4 8
3 9 27
Входные данные
5
Результат работы
1 1 1
2 4 8
3 9 27
4 16 64
5 25 125
*/

int main(int argc, char* argv[])
{
    uint8_t n = 0;

    // printf("Input the number n as a natural number less than 100: ");
    scanf("%" SCNu8 , &n);

    if (n < 1 || n > 100)
        return EXIT_FAILURE;

    for (uint8_t i = 1; i <= n; i++)
        printf("%" PRIu8 " %" PRIu16 " %" PRIu32 "\n", i, i * i, i * i * i);

    return EXIT_SUCCESS;
}
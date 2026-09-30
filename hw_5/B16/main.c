#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Наибольший общий делитель
Составить программу для вычисления НОД с помощью алгоритма Евклида. Даны два натуральных числа. Найти наибольший общий делитель.

Формат входных данных
Два неотрицательных целых числа
Формат результата
Одно целое число наибольший общий делитель
Примеры
Входные данные
14 21
Результат работы
7
Входные данные
27 18
Результат работы
9
*/

int main(int argc, char* argv[])
{
    uint32_t    a = 0,
                b = 0;
    
    // printf("Input two natural numbers: ");
    scanf("%" SCNu32 " %" SCNu32, &a, &b);

    if (!a || !b)
        return EXIT_FAILURE;

    while (b)
    {
        uint32_t t = b;
        b = a % b;
        a = t;
    }
    
    printf("%" PRIu32 "\n", a);

    return EXIT_SUCCESS;
}
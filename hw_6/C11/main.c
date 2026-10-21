#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
НОД
Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования. int nod(int a, int b)

Формат входных данных
Два целых положительных числа
Формат результата
Одно целое число - наибольший общий делитель.
Примеры
Входные данные
14 21
Результат работы
7
*/

uint32_t nod(uint32_t a, uint32_t b);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    uint32_t    a = 0,
                b = 0;

    scanf("%" SCNu32 " %" SCNu32, &a, &b);
    printf("%" PRIu32, nod(a, b));

    return EXIT_SUCCESS;
}

uint32_t nod(uint32_t a, uint32_t b)
{
    while (b)
    {
        uint32_t t = b;
        b = a % b;
        a = t;
    }
    return a;
}

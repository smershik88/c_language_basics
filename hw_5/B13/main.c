#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Количество четных и нечетных цифр
Посчитать количество четных и нечетных цифр числа.

Формат входных данных
Одно целое неотрицательное число.
Формат результата
Два числа через пробел. Количество четных и нечетных цифр в числе.
Примеры
Входные данные
1234
Результат работы
2 2
Входные данные
787
Результат работы
1 2
*/

int main(int argc, char* argv[])
{
    uint32_t n = 0;
    uint8_t odd_counter = 0,
            even_counter = 0;
    
    // printf("Input an integer >= 0: ");
    scanf("%" SCNu32, &n);


    while (n)
    {
        uint8_t digit = (uint8_t)(n % 10);
        n /= 10;
        
        if (digit & 1U)
            ++odd_counter;
        else
            ++even_counter;
    }

    printf("%" PRIu8 " %" PRIu8 "\n", even_counter, odd_counter);

    return EXIT_SUCCESS;
}
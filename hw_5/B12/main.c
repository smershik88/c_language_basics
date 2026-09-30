#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Наименьшая и наибольшая цифра
Организовать ввод натурального числа с клавиатуры. Программа должна определить наименьшую и наибольшую цифры, которые входят в состав данного натурального числа.

Формат входных данных
Целое неотрицательное число
Формат результата
Две цифры через пробел. Сначала наименьшая цифра числа, затем наибольшая.
Примеры
Входные данные
15
Результат работы
1 5
Входные данные
2457
Результат работы
2 7
Входные данные
22
Результат работы
2 2
*/

int main(int argc, char* argv[])
{
    uint32_t n = 0;
    
    // printf("Input an integer >= 0: ");
    scanf("%" SCNu32, &n);

    uint8_t min = (uint8_t)(n % 10),
            max = 0;

    while (n)
    {
        uint8_t digit = (uint8_t)(n % 10);
        n /= 10;
        min = digit < min ? digit : min;
        max = digit > max ? digit : max;
    }

    printf("%" PRIu8 " %" PRIu8 "\n", min, max);

    return EXIT_SUCCESS;
}
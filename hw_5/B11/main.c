#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Перевернуть число
Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.

Формат входных данных
Целое неотрицательное число
Формат результата
Целое не отрицательное число наоборот
Примеры
Входные данные
1234
Результат работы
4321
Входные данные
782
Результат работы
287
*/

int main(int argc, char* argv[])
{
    uint32_t n = 0;
    uint32_t reversed_n = 0;
    
    // printf("Input an integer >= 0: ");
    scanf("%" SCNu32, &n);
    
    if (n < 10)
    {
        printf("%" PRIu32, n);
        return EXIT_SUCCESS;
    }

    int8_t number_of_digits = (int8_t)log10(n) + 1;    

    for (int8_t i = number_of_digits - 1; i >= 0; i--)
    {
        uint8_t digit = (uint8_t)(n % 10);
        reversed_n += (uint32_t)(digit * pow(10, i));
        n /= 10;
    }
    
    printf("%" PRIu32 "\n", reversed_n);

    return EXIT_SUCCESS;
}
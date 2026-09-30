#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Сумма цифр равна 10
Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.

Формат входных данных
Натуральное число
Формат результата
YES или NO
Примеры
Входные данные
1234
Результат работы
YES
Входные данные
1233
Результат работы
NO
*/

int main(int argc, char* argv[])
{
    uint32_t n = 0,
             s = 0;
    
    // printf("Input an one natural number: ");
    scanf("%" SCNu32, &n);

    while (n)
    {
        uint8_t digit = (uint8_t)(n % 10);
        n /= 10;

        s += digit;
    }

    printf("%s\n", s == 10 ? "YES" : "NO");   
    
    return EXIT_SUCCESS;
}
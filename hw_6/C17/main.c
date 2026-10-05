#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Сумма цифр равна произведению
Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению. int is_happy_number(int n)

Формат входных данных
Целое не отрицательное число
Формат результата
YES или NO
Примеры
Входные данные
123
Результат работы
YES
Входные данные
528
Результат работы
NO
*/

bool is_happy_number(uint32_t n);

int main(int argc, char* argv[])
{
    uint32_t n = 0 ;

    scanf("%" SCNu32, &n);
    printf("%s", is_happy_number(n) ? "YES" : "NO");

    return EXIT_SUCCESS;
}


bool is_happy_number(uint32_t n)
{
    uint32_t s = 0,
             p = 1;

    while(n)
    {
        uint8_t digit = (uint8_t)(n % 10);
        n /= 10;

        s += digit;
        p *= digit;
    }

    return s == p;
}

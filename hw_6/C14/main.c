#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Сумма цифр четна
Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. Используя эту функцию решить задачу.

Формат входных данных
Одно целое не отрицательное число
Формат результата
Ответ YES или NO
Примеры
Входные данные
136
Результат работы
YES
Входные данные
245
Результат работы
NO
*/

bool is_digits_sum_even(uint32_t n);

int main(int argc, char* argv[])
{
    uint32_t n = 0 ;

    scanf("%" SCNu32, &n);
    printf("%s", is_digits_sum_even(n) ? "YES" : "NO");

    return EXIT_SUCCESS;
}

bool is_digits_sum_even(uint32_t n)
{
    uint8_t digits_sum = 0;
    while (n)
    {
        uint8_t digit = (uint8_t)(n % 10);
        n /= 10;
        digits_sum += digit;
    }

    return !(digits_sum & 1U);
}

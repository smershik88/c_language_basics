#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Две одинаковые цифры рядом
Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом.

Формат входных данных
Одно целое число
Формат результата
Единственное слов: YES или NO
Примеры
Входные данные
1232
Результат работы
NO
Входные данные
1224
Результат работы
YES
*/

int main(int argc, char* argv[])
{
    int32_t n = 0;
    
    // printf("Input an integer >= 0: ");
    scanf("%" SCNd32, &n);
    
    n = abs(n);
    
    bool double_digit_flag = false;
    uint8_t prev_digit = (uint8_t)(n % 10);
    n /= 10;

    while (n)
    {
        uint8_t digit = (uint8_t)(n % 10);
        if (digit == prev_digit)
        {
            double_digit_flag = true;
            break;
        }
        n = n / 10;
        prev_digit = digit;
    }

    puts(double_digit_flag ? "YES" : "NO");

    return EXIT_SUCCESS;
}
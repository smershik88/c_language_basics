#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Две одинаковые цифры
Ввести целое число и определить, верно ли, что в его записи есть  две одинаковые цифры, НЕ обязательно стоящие рядом.

Формат входных данных
Одно целое число
Формат результата
Одно слово: YES или NO
Примеры
Входные данные
1234
Результат работы
NO
Входные данные
1242
Результат работы
YES
*/

typedef enum
{
    ZERO = 0x0001,
    ONE = 0x0002,
    TWO = 0x0004,
    THREE = 0x0008,
    FOUR = 0x0010,
    FIVE = 0x0020,
    SIX = 0x0040,
    SEVEN = 0x0080,
    EIGHT = 0x0100,
    NINE = 0x0200
} digits_t;

int main(int argc, char* argv[])
{
    int32_t n = 0;
    uint16_t digit_flags = 0x0000;
    
    // printf("Input an integer: ");
    scanf("%" SCNd32, &n);
    
    n = abs(n);
    
    bool double_digit_flag = false;

    while (n)
    {
        uint8_t digit = (uint8_t)(n % 10);

        switch (digit)
        {
        case 0:
            if ((digit_flags & ZERO) == ZERO)
                double_digit_flag = true;
            else
                digit_flags |= ZERO;
            break;
        case 1:
            if ((digit_flags & ONE) == ONE)
                double_digit_flag = true;
            else
                digit_flags |= ONE;
            break;
        case 2:
            if ((digit_flags & TWO) == TWO)
                double_digit_flag = true;
            else
                digit_flags |= TWO;
            break;
        case 3:
            if ((digit_flags & THREE) == THREE)
                double_digit_flag = true;
            else
                digit_flags |= THREE;
            break;
        case 4:
            if ((digit_flags & FOUR) == FOUR)
                double_digit_flag = true;
            else
                digit_flags |= FOUR;
            break;
        case 5:
            if ((digit_flags & FIVE) == FIVE)
                double_digit_flag = true;
            else
                digit_flags |= FIVE;
            break;
        case 6:
            if ((digit_flags & SIX) == SIX)
                double_digit_flag = true;
            else
                digit_flags |= SIX;
            break;
        case 7:
            if ((digit_flags & SEVEN) == SEVEN)
                double_digit_flag = true;
            else
                digit_flags |= SEVEN;
            break;
        case 8:
            if ((digit_flags & EIGHT) == EIGHT)
                double_digit_flag = true;
            else
                digit_flags |= EIGHT;
            break;
        case 9:
            if ((digit_flags & NINE) == NINE)
                double_digit_flag = true;
            else
                digit_flags |= NINE;
            break;
        default:
            break;
        }

        n = n / 10;
    }

    puts(double_digit_flag ? "YES" : "NO");

    return EXIT_SUCCESS;
}
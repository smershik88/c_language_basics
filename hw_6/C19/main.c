#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Сумма цифр в тексте
Составить функцию, которая преобразует текущий символ цифры в число. Написать программу считающую сумму цифр в тексте. int digit_to_num(char c)

Формат входных данных
Строка состоящая из английских букв, пробелов, знаков препинания. В конце строки символ точка.
Формат результата
Целое число - сумма цифр в тексте
Примеры
Входные данные
1Hello 36world.
Результат работы
10
Входные данные
abc 1def2 3.
Результат работы
6
*/

bool is_digit(char n);
uint8_t digit_to_num(char c);

int main(int argc, char* argv[])
{
    char ch = 0;
    uint32_t digits_sum = 0;

    do
    {
        ch = (char)getchar();
        if (is_digit(ch))
            digits_sum += digit_to_num(ch);
    } while (ch != '.');
    
    printf("%" PRIu32, digits_sum);

    return EXIT_SUCCESS;
}

bool is_digit(char n)
{    
    return n >= '0' && n <= '9';
}

uint8_t digit_to_num(char c)
{
    return (uint8_t)(c - '0');
}

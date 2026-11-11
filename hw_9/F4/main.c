#include <ctype.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Цифры в строке
Написать только одну функцию. Всю программу отправлять не надо. Вывести в порядке возрастания цифры,
входящие в строку. Цифра - количество. Функция должно строго соответствовать прототипу: void
print_digit(char s[])

Input format
Строка из английских букв, пробелов, знаков препинания и цифр
Output format
Функция должна принмать на вход строку и выводить на печать по формату: Цифра пробел количество.
Examples
Input
Hello123 world77.
Output
1 1
2 1
3 1
7 2
*/

#define DEC_DIGITS_NUMBER 10

void get_number_of_dec_digits(const char *str, uint32_t digits_count[]);
void print_number_of_dec_digits(const uint32_t digits_count[]);
void print_digit(char s[]);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    char string[] = "Hello123 world77.";

    print_digit(string);

    return EXIT_SUCCESS;
}

void print_digit(char s[])
{
    if (!s)
    {
        return;
    }

    unsigned int digits_count[DEC_DIGITS_NUMBER] = {0};

    for (; *s; s++)
    {
        if (isdigit((unsigned char)*s))
        {
            digits_count[*s - '0']++;
        }
    }

    for (unsigned char i = 0; i < DEC_DIGITS_NUMBER; i++)
    {
        if (digits_count[i])
        {
            printf("%d %u\n", i, digits_count[i]);
        }
    }
}

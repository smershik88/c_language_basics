#include <ctype.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Цифры по возрастанию
Написать функцию и программу демонстрирующую работу данной функции. Вывести в порядке возрастания
цифры, входящие в десятичную запись натурального числа N, не более 1000 цифр. Цифра пробел сколько
раз данная цифра встречается в числе.

Input format
Натуральное число не более 1000 цифр
Output format
Цифры входящие в число через пробел в порядке возрастания. От самой младшей цифры до самой старшей и
количество. Examples Input 54321 Output 1 1 2 1 3 1 4 1 5 1 Input 22443344 Output 2 2 3 2 4 4
*/

#define MAX_LENGTH        1001U
#define DEC_DIGITS_NUMBER 10U

void get_number_of_dec_digits(const char *str, uint32_t digits_count[]);
void print_number_of_dec_digits(const uint32_t digits_count[]);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    char     str[MAX_LENGTH]                 = {0};
    uint32_t digits_count[DEC_DIGITS_NUMBER] = {0};

    if (!fgets(str, MAX_LENGTH, stdin))
        return EXIT_FAILURE;

    get_number_of_dec_digits(str, digits_count);
    print_number_of_dec_digits(digits_count);

    return EXIT_SUCCESS;
}

void get_number_of_dec_digits(const char *str, uint32_t digits_count[])
{
    if (!str || !digits_count)
        return;

    for (; *str; str++)
    {
        if (isdigit((unsigned char)*str))
            digits_count[*str - '0']++;
    }
}

void print_number_of_dec_digits(const uint32_t digits_count[])
{
    if (!digits_count)
        return;

    for (uint8_t i = 0; i < DEC_DIGITS_NUMBER; i++)
    {
        if (digits_count[i])
            printf("%" PRIu8 " %" PRIu32 "\n", i, digits_count[i]);
    }
}

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Количество цифр в тексте
Составить логическую функцию, которая определяет, что текущий символ это цифра. Написать программу считающую количество цифр в тексте. int is_digit(char c)

Формат входных данных
Текст из английских букв и знаков препинания. В конце текста символ точка.
Формат результата
Одно целое число - количество цифр в тексте.
Примеры
Входные данные
1Hello 36world.
Результат работы
3
Входные данные
abcd.
Результат работы
0
*/

bool is_digit(char n);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    char ch = 0;
    uint32_t char_counter = 0;

    do
    {
        ch = (char)getchar();
        if (is_digit(ch))
            char_counter++;
    } while (ch != '.');
    
    printf("%" PRIu32, char_counter);

    return EXIT_SUCCESS;
}

bool is_digit(char n)
{    
    return n >= '0' && n <= '9';
}

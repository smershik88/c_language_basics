#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Строка наоборот
Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот. Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.
void reverse_string()

Input format
Строка из английских букв и знаков препинания. В конце строки символ точка.
Output format
Исходная строка задом наперед.
Examples
Input
Hello world!.
Output
!dlrow olleH
*/

void print_reversed_input();

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    print_reversed_input();
    
    return EXIT_SUCCESS;
}

void print_reversed_input()
{
    char c = (char)getchar();
    if (c == '.')
        return;

    print_reversed_input();

    putchar(c);
}

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Большими буквами
Составить функцию, которая переводит латинскую строчную букву в заглавную. И показать пример ее
использования.

Input format
Строка состоящая из английских букв, пробелов и запятых. В конце строки символ точка.
Output format
Исходная строка в которой маленькие английские буквы заменены заглавными.
Examples
Input
hello World!.
Output
HELLO WORLD!
Input
abc, def.
Output
ABC, DEF
*/

#define BIT_NUMBER 5U

int toUpperCase(int a);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    for (int a = getchar(); a != EOF && a != '.'; a = getchar())
    {
        putchar(toUpperCase(a));
    }

    return EXIT_SUCCESS;
}

int toUpperCase(int a)
{
    if (a >= 'a' && a <= 'z')
    {
        return (int)((unsigned int)a & ~(1U << BIT_NUMBER));
    }
    else
    {
        return a;
    }
}

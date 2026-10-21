#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Большими буквами
Составить функцию, которая переводит латинскую строчную букву в заглавную. И показать пример ее использования.

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

char toUpperCase(char a);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    for (char a = (char)getchar(); a != '.'; a = (char)getchar())
    {
        putchar(toUpperCase(a));
    }

    return EXIT_SUCCESS;
}

char toUpperCase(char a)
{
    if (a >= 'a' && a <= 'z')
        return a & (char)~(1U << 5);
    else
        return a;
}
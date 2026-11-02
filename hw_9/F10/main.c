#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Упаковать строку
Дана строка состоящая из маленьких латинских букв 'a'..'z'. В конце строки точка. Необходимо заменить повторяющиеся буквы на <буква><количество повторений>

Input format
Входная строка состоящая из букв 'a'-'z' не превышающая 1000 символов. В конце строки символ '.'
Output format
Результат состоящий из букв и чисел, без пробелов
Examples
Input
aaaaabbbc.
Output
a5b3c1
Input
zzzzzzzzzzz.
Output
z11
Input
aaabbbbaa.
Output
a3b4a2
*/

size_t compress_input(char *buffer, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    char buffer[2001] = {0};

    compress_input(buffer, sizeof buffer);
    printf("%s", buffer);

    return EXIT_SUCCESS;
}

size_t compress_input(char *buffer, size_t size)
{
    if (!buffer || !size)
        return 0;

    size_t result_len = 0;
    
    int c = getchar();
    int prev_c = c;
    size_t len = 1;

    while (c != '.' && c != EOF)
    {
        c = getchar();
        if (c == prev_c)
        {
            len++;
        }
        else
        {
            int j = sprintf(buffer, "%c%zu", prev_c, len);

            if (j < 0)
                return 0;

            result_len += (size_t)j;
            buffer += j;

            prev_c = c;
            len = 1;
        }
    }
    
    return result_len;
}

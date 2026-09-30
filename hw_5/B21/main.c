#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Заглавные буквы в строчные
Дан текст состоящий из английских букв и цифр, заканчивается символом «.» Перевести все заглавные английские буквы в строчные.

Формат входных данных
Текст из маленьких, больших английских букв и пробелов. В конце текста символ точка.
Формат результата
Текст из маленьких английских букв.
Примеры
Входные данные
HELLO wORld.
Результат работы
hello world
Входные данные
ABC   d.
Результат работы
abc   d
Входные данные
small letters.
Результат работы
small letters
*/

int main(int argc, char* argv[])
{
    char letter = 0;

    // printf("Input a text with '.' at the end: ");
    
    do
    {
        scanf("%c", &letter);
        if (letter >= 'A' && letter <= 'Z')
            letter += ('a' - 'A');
        if (letter != '.')
            printf("%c", letter);
    } while (letter != '.');
    
    return EXIT_SUCCESS;
}
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Скобки
Проверить строку состоящую из скобок "(" и ")" на корректность.

Формат входных данных
На вход подается строка состоящая из символов '(', ')' и заканчивающаяся символом '.'. Размер строки не более 1000 символов.
Формат результата
Необходимо напечатать слово YES если скобки расставлены верно и NO в противном случае.
Примеры
Входные данные
(()()).
Результат работы
YES
Входные данные
()(.
Результат работы
NO
*/

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    char ch = 0;
    int32_t balance = 0;

    do
    {
        ch = (char)getchar();
        if (ch == '(')
        {
            balance++;
        }
        else if (ch == ')')
        {
            if (--balance < 0)
                break;
        }
        else if (ch == '.')
        {
            break;
        }
    } while (true);
    
    printf("%s", balance == 0 ? "YES" : "NO");

    return EXIT_SUCCESS;
}

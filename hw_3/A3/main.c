#include <stdio.h>
#include <stdlib.h>

/*
Сумма трех чисел
Ввести три числа, найти их сумму.

Формат входных данных
Три целых числа

Формат результата
Строка вида %d+%d+%d=%d

Примеры
Входные данные
4 5 7
Результат работы
4+5+7=16
Входные данные
10 20 30
Результат работы
10+20+30=60
*/

int main(int argc, char* argv[])
{
    int a = 0,
        b = 0,
        c = 0,
        s = 0;

    // printf("Input three integer numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    s = a + b + c;

    printf("%d+%d+%d=%d\n", a, b, c, s);

    return EXIT_SUCCESS;
}

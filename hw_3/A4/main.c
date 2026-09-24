#include <stdio.h>
#include <stdlib.h>

/*
Сумма и произведение трех чисел
Ввести три числа, найти их сумму и произведение.

Формат входных данных
Три целых числа через пробел.

Формат результата
Строка вида
%d+%d+%d=%d
%d*%d*%d=%d

Примеры
Входные данные
1 2 3
Результат работы
1+2+3=6
1*2*3=6
Входные данные
4 5 7
Результат работы
4+5+7=16
4*5*7=140
*/

int main(int argc, char* argv[])
{
    int a = 0,
        b = 0,
        c = 0,
        s = 0,
        p = 0;

    // printf("Input three integer numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    s = a + b + c;
    p = a * b * c;

    printf("%d+%d+%d=%d\n", a, b, c, s);
    printf("%d*%d*%d=%d\n", a, b, c, p);

    return EXIT_SUCCESS;
}

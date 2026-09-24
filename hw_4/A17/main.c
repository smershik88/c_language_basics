#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Какое время года
Ввести номер месяца и вывести название времени года.

Формат входных данных
Целое число от 1 до 12 - номер месяца.
Формат результата
Время года на английском: winter, spring, summer, autumn
Примеры
Входные данные
4
Результат работы
spring
Входные данные
1
Результат работы
winter
*/

typedef enum
{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULE,
    AUGEST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} months_t;

int main(int argc, char* argv[])
{
    int8_t mounth_number = 0;

    // printf("Input mounth number as integer: ");
    scanf("%" SCNd8, &mounth_number);

    switch (mounth_number)
    {
    case DECEMBER:
    case JANUARY:
    case FEBRUARY:
        puts("winter");
        break;
    case MARCH:
    case APRIL:
    case MAY:
        puts("spring");
        break;
    case JUNE:
    case JULE:
    case AUGEST:
        puts("summer");
        break;
    case SEPTEMBER:
    case OCTOBER:
    case NOVEMBER:
        puts("autumn");
        break;
    default:
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
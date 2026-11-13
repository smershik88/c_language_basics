#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Клетки
Известно, что шахматная доска имеет размерность 8х8 и состоит из клеток 2х цветов, например, черного
и белого (см. рисунок). Каждая клетка имеет координату, состоящую из буквы и цифры. Горизонтальное
расположение клетки определяется буквой от A до H, а вертикальное – цифрой от 1 до 8. Заметим, что
клетка с координатой А1 имеет черный цвет. Требуется по заданной координате определить цвет клетки.

Input format
В единственной строке входного файла записана координата клетки на шахматной доске: всего два
символа – буква и цифра (без пробелов).
Output format В выходной файл нужно вывести «WHITE», если
указанная клетка имеет белый цвет и «BLACK», если она черная.
Examples
Input
C3
Output
BLACK
Input
G8
Output
WHITE
*/

#define COL_ROW_MIN                 1
#define COL_ROW_MAX                 8
#define SQUARE_COORDS_BUFFER_LENGTH 3

typedef struct
{
    unsigned int col;
    unsigned int row;
} square_coords_t;

square_coords_t string_to_square_coords(const char *s);
bool            is_white_square(unsigned col, unsigned row);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    char square_coords[SQUARE_COORDS_BUFFER_LENGTH] = {0};
    if (scanf("%1[a-hA-H]%1[1-8]", square_coords, square_coords + 1) != 2)
    {
        return EXIT_FAILURE;
    }

    printf("%s\n", square_coords);

    square_coords_t sc = string_to_square_coords(square_coords);

    printf("%s", is_white_square(sc.col, sc.row) ? "WHITE" : "BLACK");

    return EXIT_SUCCESS;
}

square_coords_t string_to_square_coords(const char *s)
{
    unsigned int col = 0;
    unsigned int row = 0;

    if (s == NULL)
    {
        return (square_coords_t){col, row};
    }

    if (s[0] >= 'a' && s[0] <= 'h')
    {
        col = s[0] - 'a' + 1;
    }
    else if (s[0] >= 'A' && s[0] <= 'H')
    {
        col = s[0] - 'A' + 1;
    }

    if (s[1] >= '1' && s[1] <= '8')
    {
        row = s[1] - '1' + 1;
    }

    return !col && !row ? (square_coords_t){0, 0} : (square_coords_t){col, row};
}

bool is_white_square(unsigned col, unsigned row)
{
    bool result = false;

    if (col < COL_ROW_MIN || col > COL_ROW_MAX || row < COL_ROW_MIN || row > COL_ROW_MAX)
    {
        return result;
    }

    if (((col * row) & 1U) == 0)
    {
        result = true;
    }

    return result;
}

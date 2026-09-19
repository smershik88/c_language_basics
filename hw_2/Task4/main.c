#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    puts("A -> B = !A || B");
    puts("A\tB\t!A\t!A || B");

    for (size_t i = 0; i <= 1; i++)
    {
        for (size_t j = 0; j <= 1; j++)
        {
            printf("%d\t%d\t%d\t%d\n", i, j, !i, !i || j);
        }
    }

    puts("\nA <-> B = (A && B) || (!A && !B)");
    puts("A\tB\tA && B\t!A\t!B\t(!A && !B)\t(A && B) || (!A && !B)");

    for (size_t i = 0; i <= 1; i++)
    {
        for (size_t j = 0; j <= 1; j++)
        {
            printf("%d\t%d\t%d\t%d\t%d\t%d\t\t%d\n",
                i, j, i && j, !i, !j, ! i&& !j, i && j || !i && !j
            );
        }
    }

    return EXIT_SUCCESS;
}
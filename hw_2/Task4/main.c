#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    puts("A -> B = !A || B");
    puts("A\tB\t!A\t!A || B");

    for (unsigned int i = 0; i <= 1; i++)
    {
        for (unsigned int j = 0; j <= 1; j++)
        {
            printf("%u\t%u\t%u\t%u\n", i, j, !i, !i || j);
        }
    }   

    puts("\nA <-> B = (A && B) || (!A && !B)");
    puts("A\tB\tA && B\t!A\t!B\t(!A && !B)\t(A && B) || (!A && !B)");

    for (unsigned int i = 0; i <= 1; i++)
    {
        for (unsigned int j = 0; j <= 1; j++)
        {
            printf("%u\t%u\t%u\t%u\t%u\t%u\t\t%u\n",
                i, j, i && j, !i, !j, ! i&& !j, (i && j) || (!i && !j)
            );
        }
    }

    return EXIT_SUCCESS;
}
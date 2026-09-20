#include <stdio.h>
#include <stdlib.h>

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

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int a = 0,
        b = 0,
        c = 0;
    double avg = 0.0;

    // printf("Input three integer numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    avg = (a + b + c) / 3.0;

    printf("%.2f\n", avg);

    return EXIT_SUCCESS;
}

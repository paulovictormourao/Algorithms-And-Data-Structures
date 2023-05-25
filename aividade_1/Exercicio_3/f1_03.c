#include <stdio.h>

void print(double *vet)
{
    int i;
    double total = 0;

    printf("Grades: ");

    for(i = 0; i < 4; i++)
    {
        total += *(vet+ i);
        printf("%.2f   ", *(vet + i));
    }

    printf("\nAverage: %.2f\n", total/4);
}

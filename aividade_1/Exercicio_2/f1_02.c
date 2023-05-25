#include <stdio.h>

void invert(double *vet)
{
    int i;
    for(i = 9; i > -1; i--)
    {
        printf("%f\n", *(vet + i));
    }
}

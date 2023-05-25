#include <stdio.h>
#define SIZE  100

void fill(double *vet)
{
    double grade;
    int j, i;

    for (j = 0; j < SIZE; j++) {
        double total = 0;

        for (i = 0; i < 4; i++) {

            scanf("%lf", &grade);
            total += grade;

        }
        vet[j] = total/4;

    }
}


void print_average(double vet[SIZE]) {
    int i;
    double average;

    for(i = 0; i < SIZE; i++)
    {
        average = vet[i];

        if (average >= 7){
            printf("%.1f\n", average);
        }

    }
}
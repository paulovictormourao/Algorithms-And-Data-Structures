#ifndef ALGORITHMS_AND_DATA_STRUCTURES_F1_04_H
#define ALGORITHMS_AND_DATA_STRUCTURES_F1_04_H

#endif //ALGORITHMS_AND_DATA_STRUCTURES_F1_04_H
#include <stdio.h>
#define SIZE  2

void print_average(const double vet[SIZE]) {
    int i;

    for(i = 0; i < SIZE; i++)
    {
        printf("%.1f\n", vet[i]/4);
    }
}
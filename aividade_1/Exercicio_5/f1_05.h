//
// Created by Samsung on 20/05/2023.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_F1_05_H
#define ALGORITHMS_AND_DATA_STRUCTURES_F1_05_H

#endif //ALGORITHMS_AND_DATA_STRUCTURES_F1_05_H
#include <stdio.h>

void fill(float *vet, float *even, float *odd)
{
    int i, x;

    for (i = 0; i < 20; i++)
    {
        scanf("%d", &x);

        *(vet + i) = x;

        if (x % 2 == 0)
        {
            *(even + i) = x;
            *(odd + i) = 0.1;
        }

        else
        {

            *(odd + i) = x;
            *(even + i) = 0.1;
        }

    }
}

void print_select(float *vet)
{
    int i;


    for (i = 0; i < 20; i++)
    {
        if ((*(vet + i) > 0) && (*(vet + i) < 1))
        {
            continue;
        }

        else
            printf(" %.0f", *(vet + i) );
    }
}
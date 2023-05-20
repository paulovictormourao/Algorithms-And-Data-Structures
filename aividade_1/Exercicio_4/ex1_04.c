/*

	Name: Paulo Victor Mourão
	Mat:  2215310043
	
	exercise 1.04
*/ 

#include <stdio.h>
#include "f1_04.h"


int main(int argc, char** argv)
{

    int j, i;
    double grade, vet[SIZE];

    for (j = 0; j < SIZE; j++) {
        double total = 0;

        for (i = 0; i < 4; i++) {

            scanf("%lf", &grade);
            total += grade;

        }
        vet[j] = total;
    }

    print_average(vet);

}

/*

	Name: Paulo Victor Mourao
	Mat:  2215310043
	
	exercise 1.05
*/ 

#include <stdio.h>
#include "f1_05.h"


int main(int argc, char** argv)
{
	int i;
	float vet[20], even[20], odd[20];

    fill(vet, even, odd);
	
	printf("all: ");
	for (i = 0; i < 20; i++)
	{
		printf(" %.0f", vet[i]);
	}

    printf("\neven: ");
    print_select(even);

    printf("\nodd: ");
    print_select(odd);
			

	
}

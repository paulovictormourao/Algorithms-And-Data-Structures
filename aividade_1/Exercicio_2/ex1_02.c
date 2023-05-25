/*

	Name: Paulo Victor Mourao
	Mat:  2215310043
	
	exercise 1.02
*/ 

#include <stdio.h>
#include "f1_02.c"

int main(int argc, char** argv)
{
	int i;
	double vet[10];
	
	
	for(i = 0; i < 10; i++)
	{
		scanf("%lf", &vet[i]);
	}

    invert(vet);


	
}

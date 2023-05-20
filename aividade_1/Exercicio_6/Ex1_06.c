/*

	Name: Paulo Victor Mourao
	Mat:  2215310043

	exercise 1.06
*/


#include <stdio.h>
#include "f1_06.h"

int main (int argc, char** argv)
{
	int m, n, p;


	printf("A[m][n] X B[n][p]:\n");

	printf("Matrix A lines: ");
	scanf("%d", &m);

	printf("Matrix A columns and Matrix B lines: ");
	scanf("%d", &n);

	printf("Matrix B columns: ");
	scanf("%d", &p);

    float A[m][n], B[n][p], C[m][p];


    fill(A, m, n);
    fill(B, n, p);

    multiply(A, B, C, m, n, p);

    print(C, m, p);


}

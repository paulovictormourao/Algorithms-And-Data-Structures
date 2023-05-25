/*
	Name: Paulo Victor Mourao
	Mat:  2215310043

	exercise 1.07


 */

#include <stdio.h>
#include "f1_07.c"

int main (int argc, char** argv) {

    int m;


    printf("Matrix A dimension: ");
    scanf("%d", &m);

    int mat[m][m];

    fill(mat, m);

    if ( verify(mat, m) == 1)
    {
        printf("A is a magic square");

    }

    else
    {
        printf("A is NOT a magic square");

    }

}
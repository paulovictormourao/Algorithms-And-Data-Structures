#include <stdio.h>

void fill (float *matrix, int dimension)
{
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("[%d][%d]: ", i + 1, j + 1);
            scanf("%f", matrix + i * dimension + j);
        }
    }
}


int verify (int *matrix, int dimension) {

    int i, j, sum_aux, sum_d2, sum_test = 0;

    // Sum lines
    for (i = 0; i < dimension; i++)
    {
        sum_aux  = 0;


        for (j = 0; j < dimension; j++)
        {
            sum_aux += * (matrix + i * dimension + j);
        }

        if (i == 0)
        {
            sum_test = sum_aux;
        }

        else
        {

            if (sum_aux != sum_test) {
                return 0;
            }
        }
    }


    for (j = 0; j < dimension; j++) {

        sum_aux = 0;

        for (i = 0; i < dimension; i++)
        {
            sum_aux += *(matrix + (i * dimension) + j);
        }

        if (sum_aux != sum_test)
        {
            return 0;
        }
    }

    // Diagonal
    sum_aux = 0;
    sum_d2 = 0;

    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            if (i ==  j)
            {
                sum_aux += *(matrix + (i * dimension) + j);
            }

            if (i + j == dimension - 1)
            {
                sum_d2 += *(matrix + (i * dimension) + j);
            }

        }

    }

    if ( (sum_aux != sum_test) || (sum_d2 != sum_test) ) {
        return 0;
    }

    return 1;
}
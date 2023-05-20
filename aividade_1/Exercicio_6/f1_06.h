#ifndef ALGORITHMS_AND_DATA_STRUCTURES_F1_06_H
#define ALGORITHMS_AND_DATA_STRUCTURES_F1_06_H

#endif //ALGORITHMS_AND_DATA_STRUCTURES_F1_06_H


void multiply (float *A, float *B, float *C, int m, int n, int p)
{

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < p; j++)
        {
            *(C + i * p + j) = 0;

            for (int k = 0; k < n; k++)
            {
                *(C + i * p + j) += *(A + i * n + k) * *(B + k * p + j);
            }
        }
    }
}

void fill (float *matrix, int lines, int columns)
{
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            printf("[%d][%d]: ", i + 1, j + 1);
            scanf("%f", matrix + i * columns + j);
        }
    }
}

void print(float *matrix, int lines, int columns)
{
    int i, j;

    for (i = 0; i < lines; i++) {
        for (j = 0; j < columns; j++) {
            printf("%.1f ", * (matrix + (i * columns) + j) );
        }
        printf("\n");
    }
}
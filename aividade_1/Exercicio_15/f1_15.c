#include <stdio.h>
#include <stdlib.h>

struct dma
{
    int dia;
    int mes;
    int ano;
};

typedef struct dma dma;

dma fill()
{
    dma dx = {0, 0, 0};
    int day, month, year;

    printf("day: ");
    scanf("%d", &day);
    dx.dia = day;

    printf("month: ");
    scanf("%d", &month);
    dx.mes = month;

    printf("year: ");
    scanf("%d", &year);
    dx.ano = year;

    return dx;
}

void distance_days (dma d1, dma d2)
{
    int total = 0;

    total += abs(d1.dia - d2.dia);
    total += 30 * abs(d1.mes - d2.mes);
    total += 365 * abs(d1.ano - d2.ano);

    printf("number of days: %d", total);
}
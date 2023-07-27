/*
    Curso: Sistemas de Informação
    Disciplina: Algoritmos e Estruturas de Dados
    Name: Paulo Victor Mourao
    Mat:  2215310043

    exercise 6.2
*/
#include "f_lista2.h"

int main(int argc, char** argv)
{
    No *lista;


    lista = criar();

    for(int i = 0; i < 4; i++){
        int num;
        scanf("%d", &num);
        lista = adicionar_inicio(lista, num);
    }

    imprimir(lista);
    adicionar_fim(&lista, 9);
    imprimir(lista);

    return 0;
}


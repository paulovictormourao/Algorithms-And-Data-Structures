/*
    Curso: Sistemas de Informação
    Disciplina: Algoritmos e Estruturas de Dados
    Name: Paulo Victor Mourao
    Mat:  2215310043

    exercise 6.1
*/
#include "f_lista1.h"

int main(int argc, char** argv)
{
    No *lista;

    lista = criar();

    for(int i = 0; i < 5; i++){
        int num;
        scanf("%d", &num);
        lista = inserir(lista, num);
    }

    imprimir( lista );

    int num;
    scanf("%d", &num);
    excluir_elemento(&lista, num);

    imprimir( lista );


    return 0;
}

/*
   Curso: Sistemas de Informação
   Disciplina: Algoritmos e Estruturas de Dados I
   Alunos: Evelyn Sabrina Bessa
                Gisele de Sá
                Gabriel Dias Rejtman
                Josue Azevedo Gomes
                Paulo Victor Mourão da Costa
                Raquel Karolyne Carlotto Santos
                William Matheus de Souza Cunha
                Yago De Almeida Nunes
   Matrículas respectivas: 2215310007
                                        2215310009
                                        2215310051
                                        2215310054
                                        2215310043
                                        2215310044
                                        2215310030
                                        2215310059
*/
#include "f_af.h"

int main(int argc, char** argv)
{
    Pagina *raiz = NULL;

    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 12);

    int chave_para_buscar = 6;
    Pagina *resultado = buscar(raiz, chave_para_buscar);

    if (resultado)
    {
        printf("Chave %d encontrada!\n", chave_para_buscar);
    }
    else
    {
        printf("Chave %d não encontrada.\n", chave_para_buscar);
    }

    return 0;
}

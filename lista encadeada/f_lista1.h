#include <stdio.h>
#include <stdlib.h>

/* definição da estrutura de dados */
typedef struct no No;

struct no
{
    int dado;
    No* prox;
};

/*--------------------------------------------------------------------------*/
No* criar()
{
    return NULL;
}

/*--------------------------------------------------------------------------*/
No* inserir( No *lista, int dado )
{
    No *novo;

    novo = (No *)malloc( sizeof( No ) );
    novo->dado = dado;
    novo->prox = lista;

    return novo;
}

/*--------------------------------------------------------------------------*/
No* excluir( No *lista )
{
    No *temp;

    temp = lista;
    lista = lista->prox;
    temp->prox = NULL;
    free(temp);

    return lista;

}

/*--------------------------------------------------------------------------*/
void imprimir( No *lista )
{
    No *temp;

    temp = lista;

    while( temp != NULL )
    {
        printf( "%d ", temp->dado );
        temp = temp->prox;
    }

    printf("\n");
}

/*--------------------------------------------------------------------------*/
int buscar( No *lista, int dado )
{
    No *temp;

    temp = lista;

    while( temp != NULL )
    {
        if (temp->dado == dado)
            return 1;

        temp = temp->prox;
    }

    return 0;
}

void excluir_elemento(No** lista, int buscado) {
    No * temp = *lista;
    No * prev = NULL;

    // Verifica se o elemento a ser eliminado é o primeiro da lista
    if (temp != NULL && temp->dado == buscado) {
        *lista = temp->prox;
        free(temp);
        return;
    }

    // Percorre a lista até encontrar o elemento ou o final da lista
    while (temp != NULL && temp->dado!= buscado) {
        prev = temp;
        temp = temp->prox;
    }

    // Se o elemento não foi encontrado na lista
    if (temp == NULL) {
        printf("Elemento %d não encontrado na lista.\n", buscado);
        return;
    }

    // Remove o elemento da lista
    prev->prox = temp->prox;
    temp->prox = NULL;
    free(temp);
}

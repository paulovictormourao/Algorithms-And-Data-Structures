#include <stdio.h>
#include <stdlib.h>


struct No
{
    int data;
    struct No* prev;
    struct No* next;
};

struct Descritor
{
    int qtde;
    struct No* primeiro;
    struct No* ultimo;
};


struct No* criar_no(int data)
{
    struct No* novo_no = (struct No*)malloc(sizeof(struct No));
    novo_no->data = data;
    novo_no->prev = NULL;
    novo_no->next = NULL;
    return novo_no;
}

struct Descritor* inicializar_descritor()
{
    struct Descritor* descritor = (struct Descritor*)malloc(sizeof(struct Descritor));
    descritor->qtde = 0;
    descritor->primeiro = NULL;
    descritor->ultimo = NULL;
    return descritor;
}

void inserir_no_inicio(struct Descritor* descritor, int data)
{
    struct No* novo_no = criar_no(data);

    if (descritor->qtde == 0)
    {
        descritor->primeiro = novo_no;
        descritor->ultimo = novo_no;
    }

    else
    {
        novo_no -> next = descritor->primeiro;
        descritor->primeiro->prev = novo_no;
        descritor->primeiro = novo_no;
    }
    descritor->qtde++;
}

void inserir_no_fim(struct Descritor* descritor, int data)
{

    struct No* novo_no = criar_no(data);

    if (descritor->qtde == 0)
    {
        descritor->primeiro = novo_no;
        descritor->ultimo = novo_no;
    }

    else
    {
        novo_no->prev = descritor->ultimo;
        descritor->ultimo->next = novo_no;
        descritor->ultimo = novo_no;
    }

    descritor->qtde++;
}

void excluir_do_inicio(struct Descritor* descritor)
{
    if (descritor->qtde == 0)
    {
        return;
    }

    else
    {
        struct No* temp = descritor->primeiro;
        descritor->primeiro = descritor->primeiro->next;
        if (descritor->primeiro != NULL)
        {
            descritor->primeiro->prev = NULL;
        }
        else
        {
            descritor->ultimo = NULL;
        }
        free(temp);
        descritor->qtde--;
    }
}

void excluir_do_fim(struct Descritor* descritor)
{
    if (descritor->qtde == 0)
    {
        return;
    }
    else
    {
        struct No* temp = descritor->ultimo;
        descritor->ultimo = descritor->ultimo->prev;

        if (descritor->ultimo != NULL)
        {
            descritor->ultimo->next = NULL;
        }
        else
        {
            descritor->primeiro = NULL;
        }
        free(temp);
        descritor->qtde--;
    }
}

void imprimir(struct Descritor* descritor)
{

    struct No* temp = descritor->primeiro;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

}

struct No* buscar(struct Descritor* descritor, int key)
{
    struct No* temp = descritor->primeiro;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL; // Retornar NULL se o elemento não for encontrado
}

void liberar_lista(struct Descritor* descritor)
{

    struct No* temp = descritor->primeiro;

    while (temp != NULL)
    {
        struct No* temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
    free(descritor);
}

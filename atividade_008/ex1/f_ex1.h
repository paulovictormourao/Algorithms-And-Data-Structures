#include <stdio.h>
#include <stdlib.h>

struct No
{
    int data;
    struct No* ant;
    struct No* prox;
};

struct No* criar_no(int data)
{
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->data = data;
    novoNo->ant = NULL;
    novoNo->prox = NULL;
    return novoNo;
}

void inserir_no_inicio(struct No** head, int data)
{
    struct No* novo_no = criar_no(data);
    if (*head == NULL)
    {
        *head = novo_no;
    }

    else
    {
        novo_no -> prox = *head;
        (*head) -> ant = novo_no;
        *head = novo_no;
    }
}

void inserir_no_fim(struct No** head, int data)
{
    struct No* novo_no = criar_no(data);
    if (*head == NULL)
    {
        *head = novo_no;
    }
    else
    {
        struct No* temp = *head;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = novo_no;
        novo_no->ant = temp;
    }
}

void excluir_do_inicio(struct No** head)
{
    if (*head == NULL)
    {
        return;
    }

    else
    {
        struct No* temp = *head;
        *head = (*head)->prox;

        if (*head != NULL)
        {
            (*head)->ant = NULL;
        }

        free(temp);
    }
}


void excluir_do_fim(struct No** head)
{
    if (*head == NULL)
    {
        return;
    }

    else
    {
        struct No* temp = *head;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }

        if (temp->ant != NULL)
        {
            temp->ant->prox = NULL;
        }

        else
        {
            *head = NULL;
        }

        free(temp);
    }
}

void imprimir(struct No* head)
    {
    struct No* temp = head;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);

        temp = temp->prox;
    }
}

struct No* buscar(struct No* head, int key)
    {

    struct No* temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }

        temp = temp->prox;
    }
    return NULL;
}


void liberar_lista(struct No* head)
    {
    struct No* temp = head;

    while (temp != NULL)
    {
        struct No* temp2 = temp;
        temp = temp->prox;
        free(temp2);
    }
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAVES 3

typedef struct No
{
    int chaves[MAX_CHAVES];
    struct No *filhos[MAX_CHAVES + 1];
    int num_chaves;
    struct No *pai;
} No;

No *criarNo()
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo)
    {
        novoNo->num_chaves = 0;
        novoNo->pai = NULL;
        for (int i = 0; i <= MAX_CHAVES; i++)
        {
            novoNo->filhos[i] = NULL;
        }
    }
    return novoNo;
}

void dividirFilho(No *noPai, int indiceFilho)
{
    No *filho = noPai->filhos[indiceFilho];
    No *novoFilho = criarNo();
    novoFilho->pai = noPai;

    for (int i = 0; i < MAX_CHAVES - 1; i++)
    {
        novoFilho->chaves[i] = filho->chaves[i + MAX_CHAVES];
    }

    if (filho->filhos[0] != NULL)
    {
        for (int i = 0; i < MAX_CHAVES; i++)
        {
            novoFilho->filhos[i] = filho->filhos[i + MAX_CHAVES];
            if (novoFilho->filhos[i] != NULL)
            {
                novoFilho->filhos[i]->pai = novoFilho;
            }
        }
    }

    for (int i = noPai->num_chaves; i > indiceFilho; i--)
    {
        noPai->filhos[i + 1] = noPai->filhos[i];
    }
    noPai->filhos[indiceFilho + 1] = novoFilho;

    for (int i = noPai->num_chaves - 1; i >= indiceFilho; i--)
    {
        noPai->chaves[i + 1] = noPai->chaves[i];
    }
    noPai->chaves[indiceFilho] = filho->chaves[MAX_CHAVES - 1];
    noPai->num_chaves++;
    filho->num_chaves = MAX_CHAVES - 1;
}

void inserirNaoCheio(No *no, int chave)
{
    int i = no->num_chaves - 1;
    if (no->filhos[0] == NULL)
    {
        while (i >= 0 && chave < no->chaves[i])
        {
            no->chaves[i + 1] = no->chaves[i];
            i--;
        }
        no->chaves[i + 1] = chave;
        no->num_chaves++;
    }
    else
    {
        while (i >= 0 && chave < no->chaves[i])
        {
            i--;
        }
        i++;

        if (no->filhos[i]->num_chaves == MAX_CHAVES)
        {
            dividirFilho(no, i);
            if (chave > no->chaves[i])
            {
                i++;
            }
        }
        inserirNaoCheio(no->filhos[i], chave);
    }
}

No *inserir(No *raiz, int chave)
{
    if (raiz == NULL)
    {
        No *novaRaiz = criarNo();
        novaRaiz->chaves[0] = chave;
        novaRaiz->num_chaves = 1;
        return novaRaiz;
    }

    if (raiz->num_chaves == MAX_CHAVES)
    {
        No *novaRaiz = criarNo();
        novaRaiz->filhos[0] = raiz;
        dividirFilho(novaRaiz, 0);
        inserirNaoCheio(novaRaiz, chave);
        return novaRaiz;
    }

    inserirNaoCheio(raiz, chave);
    return raiz;
}

No *buscar(No *raiz, int chave)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    int i = 0;
    while (i < raiz->num_chaves && chave > raiz->chaves[i])
    {
        i++;
    }

    if (i < raiz->num_chaves && chave == raiz->chaves[i]) {
        return raiz;
    } else if (raiz->filhos[0] == NULL)
    {
        return NULL;
    }
    else
    {
        return buscar(raiz->filhos[i], chave);
    }
}



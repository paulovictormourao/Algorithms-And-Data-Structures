#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAVES 3

typedef struct Pagina {
    int chaves[MAX_CHAVES];
    struct Pagina *filhos[MAX_CHAVES + 1];
    int num_chaves;
    struct Pagina *pai;
} Pagina;

Pagina *criarPagina() {
    Pagina *novaPagina = (Pagina *)malloc(sizeof(Pagina));
    if (novaPagina) {
        novaPagina->num_chaves = 0;
        novaPagina->pai = NULL;
        for (int i = 0; i <= MAX_CHAVES; i++) {
            novaPagina->filhos[i] = NULL;
        }
    }
    return novaPagina;
}

void dividirFilho(Pagina *paginaPai, int indiceFilho) {
    Pagina *filho = paginaPai->filhos[indiceFilho];
    Pagina *novoFilho = criarPagina();
    novoFilho->pai = paginaPai;

    for (int i = 0; i < MAX_CHAVES - 1; i++) {
        novoFilho->chaves[i] = filho->chaves[i + MAX_CHAVES];
    }

    if (filho->filhos[0] != NULL) {
        for (int i = 0; i < MAX_CHAVES; i++) {
            novoFilho->filhos[i] = filho->filhos[i + MAX_CHAVES];
            if (novoFilho->filhos[i] != NULL) {
                novoFilho->filhos[i]->pai = novoFilho;
            }
        }
    }

    for (int i = paginaPai->num_chaves; i > indiceFilho; i--) {
        paginaPai->filhos[i + 1] = paginaPai->filhos[i];
    }
    paginaPai->filhos[indiceFilho + 1] = novoFilho;

    for (int i = paginaPai->num_chaves - 1; i >= indiceFilho; i--) {
        paginaPai->chaves[i + 1] = paginaPai->chaves[i];
    }
    paginaPai->chaves[indiceFilho] = filho->chaves[MAX_CHAVES - 1];
    paginaPai->num_chaves++;
    filho->num_chaves = MAX_CHAVES - 1;
}

void inserirNaoCheio(Pagina *pagina, int chave) {
    int i = pagina->num_chaves - 1;
    if (pagina->filhos[0] == NULL) {
        while (i >= 0 && chave < pagina->chaves[i]) {
            pagina->chaves[i + 1] = pagina->chaves[i];
            i--;
        }
        pagina->chaves[i + 1] = chave;
        pagina->num_chaves++;
    } else {
        while (i >= 0 && chave < pagina->chaves[i]) {
            i--;
        }
        i++;
        if (pagina->filhos[i]->num_chaves == MAX_CHAVES) {
            dividirFilho(pagina, i);
            if (chave > pagina->chaves[i]) {
                i++;
            }
        }
        inserirNaoCheio(pagina->filhos[i], chave);
    }
}

Pagina *inserir(Pagina *raiz, int chave) {
    if (raiz == NULL) {
        Pagina *novaRaiz = criarPagina();
        novaRaiz->chaves[0] = chave;
        novaRaiz->num_chaves = 1;
        return novaRaiz;
    }

    if (raiz->num_chaves == MAX_CHAVES) {
        Pagina *novaRaiz = criarPagina();
        novaRaiz->filhos[0] = raiz;
        dividirFilho(novaRaiz, 0);
        inserirNaoCheio(novaRaiz, chave);
        return novaRaiz;
    }

    inserirNaoCheio(raiz, chave);
    return raiz;
}

Pagina *buscar(Pagina *raiz, int chave) {
    if (raiz == NULL) {
        return NULL;
    }

    int i = 0;
    while (i < raiz->num_chaves && chave > raiz->chaves[i]) {
        i++;
    }

    if (i < raiz->num_chaves && chave == raiz->chaves[i]) {
        return raiz;
    } else if (raiz->filhos[0] == NULL) {
        return NULL;
    } else {
        return buscar(raiz->filhos[i], chave);
    }
}
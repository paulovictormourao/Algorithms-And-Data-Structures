#include "f_af.h"

int main() {
    Pagina *raiz = NULL;

    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 12);

    int chave_para_buscar = 6;
    Pagina *resultado = buscar(raiz, chave_para_buscar);
    if (resultado) {
        printf("Chave %d encontrada!\n", chave_para_buscar);
    } else {
        printf("Chave %d não encontrada.\n", chave_para_buscar);
    }

    return 0;
}

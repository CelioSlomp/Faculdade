#include <stdio.h>
#include <stdlib.h>
#include "arvore_busca_binaria.h"

int main()
{
    // Cria uma arvore
    Arvbb *raiz = arvbb_cria();

    // Insere um elemento na arvore
    raiz = arvbb_insere(raiz, 7);
    raiz = arvbb_insere(raiz, 9);
    raiz = arvbb_insere(raiz, 8);
    raiz = arvbb_insere(raiz, 2);
    raiz = arvbb_insere(raiz, 3);
    raiz = arvbb_insere(raiz, 1);
    raiz = arvbb_insere(raiz, 1);
    raiz = arvbb_insere(raiz, 32);
    raiz = arvbb_insere(raiz, 51);
    raiz = arvbb_insere(raiz, 2);
    raiz = arvbb_insere(raiz, 50);
    raiz = arvbb_insere(raiz, 48);
    raiz = arvbb_insere(raiz, 36);

    // Busca uma raiz da arvore
    // printf("%d", arvbb_busca(raiz, 6)->info);

    // Imprime a lista
    arvbb_imprime(raiz);

    // Imprime descrescente
    // arvbb_imprime_decrescente(raiz);

    // Retira elementos da arvore
    raiz = arvbb_retira(raiz, 8);
    raiz = arvbb_retira(raiz, 32);
    raiz = arvbb_retira(raiz, 2);
    raiz = arvbb_retira(raiz, 50);
    raiz = arvbb_retira(raiz, 36);
    printf("\n");
    arvbb_imprime(raiz);

    return 0;
}
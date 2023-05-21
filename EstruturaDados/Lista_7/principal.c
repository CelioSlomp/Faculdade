#include "arvv.h"

int main()
{
    Arvv *a1 = arvv_cria(1);
    Arvv *a2 = arvv_cria(2);
    Arvv *a3 = arvv_cria(3);
    Arvv *a4 = arvv_cria(4);
    Arvv *a5 = arvv_cria(5);
    Arvv *a6 = arvv_cria(6);

    arvv_insere(a1, a2);
    arvv_insere(a1, a3);
    arvv_insere(a1, a4);
    arvv_insere(a2, a5);
    arvv_insere(a4, a6);

    Arvv *b1 = arvv_cria(1);
    Arvv *b2 = arvv_cria(2);
    Arvv *b3 = arvv_cria(3);
    Arvv *b4 = arvv_cria(4);
    Arvv *b5 = arvv_cria(5);
    Arvv *b6 = arvv_cria(6);

    arvv_insere(b1, b2);
    arvv_insere(b1, b3);
    arvv_insere(b1, b4);
    arvv_insere(b2, b5);
    arvv_insere(b4, b6);

    // Pertence
    // printf("%d", arvv_pertence(a1, 5));

    // Imprime a arvore
    // arvv_imprime(a1);

    // Imprime altura da arvore
    // printf("%d", arvv_altura(a1));

    // Imprime quantos numeros pares tem
    // printf("%d", arvv_pares(a1));

    // Imprime numero de folhas
    // printf("%d", arvv_folhas(a1));

    // Verifica se são iguais
    // printf("%d", arvv_igual(a1, b1));

    // Cria uma cópia
    Arvv *c1 = arvv_copia(a1);
    arvv_imprime(a1);
    printf("\n");
    arvv_imprime(c1);

    return 0;
}
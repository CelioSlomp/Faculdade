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

    // Pertence
    // printf("%d", arvv_pertence(a1, 5));

    // Imprime a arvore
    arvv_imprime(a1);

    return 0;
}
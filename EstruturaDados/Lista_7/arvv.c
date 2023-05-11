#include "arvv.h"

/* prot ́otipos das funcoes para operacoes nas arvores */
Arvv *arvv_cria(int v)
{
    Arvv *a = (Arvv *)malloc(sizeof(Arvv));
    a->info = v;
    a->prim = NULL;
    a->prox = NULL;
    return a;
}

void arvv_insere(Arvv *a, Arvv *sa)
{
    sa->prox = a->prim;
    a->prim = sa;
}

Arvv *arvv_libera(Arvv *a)
{
    if (a == NULL)
        return NULL;
    arvv_libera(a->prim);
    arvv_libera(a->prox);
    free(a);
    return NULL;
}

int arvv_pertence(Arvv *a, int n)
{
    if (a == NULL)
        return 0;
    if (a->info == n)
        return 1;
    return (arvv_pertence(a->prim, n) || arvv_pertence(a->prox, n));
}

void arvv_imprime(Arvv *a)
{
    printf("<");
    printf("%d", a->info);
    Arvv *p = a->prim;
    while (p != NULL)
    {
        arvv_imprime(p);
        p = p->prox;
    }
    printf(">");
}
int arvv_altura(Arvv *a) {}
int arvv_pares(Arvv *a) {}
int arvv_folhas(Arvv *a) {}
int arvv_ivual(Arvv *a1, Arvv *a2) {}
Arvv *arvv_copia(Arvv *a) {}
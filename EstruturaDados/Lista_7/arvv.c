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

int arvv_altura(Arvv *a)
{
    int hmax = -1;
    Arvv *no = a->prim;
    while (no != NULL)
    {
        int h = arvv_altura(no);
        if (h > hmax)
            hmax = h;
        no = no->prox;
    }
    return hmax + 1;
}

int arvv_pares(Arvv *a)
{
    int val = 0;
    if (a == NULL)
        return 0;
    if (a->info % 2 == 0)
        val++;
    return (arvv_pares(a->prim) + arvv_pares(a->prox) + val);
}

int arvv_folhas(Arvv *a)
{
    int val = 0;
    Arvv *no = a->prim;
    if (a == NULL)
        return 0;
    while (no != NULL)
    {
        val = arvv_folhas(no);
        no = no->prox;
    }
    return val + 1;
}

int arvv_igual(Arvv *a1, Arvv *a2)
{
}

Arvv *arvv_copia(Arvv *a)
{
}
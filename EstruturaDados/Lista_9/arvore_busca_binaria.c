#include <stdio.h>
#include <stdlib.h>
#include "arvore_busca_binaria.h"

Arvbb *arvbb_cria()
{
    return NULL;
}

void arvbb_imprime(Arvbb *a)
{
    printf("<");
    if (a != NULL)
    {
        arvbb_imprime(a->esq);
        printf("%d", a->info);
        arvbb_imprime(a->dir);
    }
    printf(">");
}

Arvbb *arvbb_busca(Arvbb *a, int v)
{
    if (a == NULL)
    {
        return NULL;
    }
    if (v < a->info)
    {
        return arvbb_busca(a->esq, v);
    }
    if (v > a->info)
    {
        return arvbb_busca(a->dir, v);
    }
    return a;
}

Arvbb *arvbb_insere(Arvbb *a, int v)
{
    if (a == NULL)
    {
        Arvbb *ar = (Arvbb *)malloc(sizeof(Arvbb));
        ar->info = v;
        return ar;
    }

    if (v < a->info)
    {
        a->esq = arvbb_insere(a->esq, v);
    }
    else
        a->dir = arvbb_insere(a->dir, v);
    return a;
}

Arvbb *arvbb_retira(Arvbb *a, int v)
{
    if (a == NULL)
    {
        return NULL;
    }
    else
    {
        if (v < a->info)
            a->esq = arvbb_retira(a->esq, v);
        else
        {
            if (v > a->info)
                a->dir = arvbb_retira(a->dir, v);
            else
            {
                if (a->esq == NULL && a->dir == NULL)
                {
                    free(a);
                    a = NULL;
                }
                else
                {
                    if (a->esq == NULL)
                    {
                        Arvbb *tmp = a;
                        a = a->dir;
                        free(tmp);
                    }
                    else
                    {
                        if (a->dir == NULL)
                        {
                            Arvbb *tmp = a;
                            a = a->esq;
                            free(tmp);
                        }
                        else
                        {
                            Arvbb *p = a->esq;
                            while (p->dir != NULL)
                            {
                                p = p->dir;
                            }
                            a->info = p->info;
                            p->info = v;
                            a->esq = arvbb_retira(a->esq, v);
                        }
                    }
                }
            }
        }
    }
    return a;
}

void arvbb_imprime_decrescente(Arvbb *a)
{
    printf("<");
    if (a != NULL)
    {
        arvbb_imprime_decrescente(a->dir);
        printf("%d", a->info);
        arvbb_imprime_decrescente(a->esq);
    }
    printf(">");
}
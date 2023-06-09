#include "tabela_hash.h"

int hash(int k)
{
    return k % N;
}

Aluno *hsh_get(Hash tab, int mat)
{
    int h = hash(mat);

    Aluno *al = tab[h];

    while (al != NULL)
    {
        if (al->matricula == mat)
            return al;
        al = al->prox;
    }
    return NULL;
}

Aluno *hsh_set(Hash tab, int mat, char *n, char *e, char *t)
{
    int h = hash(mat);

    Aluno *tmp = tab[h];
    while (tmp != NULL)
    {
        if (tmp->matricula == mat)
        {
            tmp->nome = n;
            tmp->turma = t;
            tmp->email = e;
            return tmp;
        }
        tmp = tmp->prox;
    }

    Aluno *al = (Aluno *)malloc(sizeof(Aluno));
    al->matricula = mat;
    al->nome = n;
    al->turma = t;
    al->email = e;
    al->prox = tab[h];
    tab[h] = al;

    return al;
}

void hsh_remove(Hash tab, int mat)
{
    int h = hash(mat);
    if (tab[h] == NULL)
        return;
    Aluno *tmp = tab[h]->prox;
    Aluno *al = tab[h];
    while (tmp != NULL)
    {
        if (tmp->matricula == mat)
        {
            al->prox = tmp->prox;
            free(tmp);
            break;
        }
        if (al->matricula == mat)
        {
            tab[h] = tmp;
            free(al);
            break;
        }
        tmp = tmp->prox;
        al = al->prox;
    }
}

void hsh_imprime(Hash tab)
{
    for (int i = 0; i < N; i++)
    {
        Aluno *tmp = tab[i];
        while (tmp != NULL)
        {
            printf("%d: %d\n", i, tmp->matricula);
            tmp = tmp->prox;
        }
    }
}
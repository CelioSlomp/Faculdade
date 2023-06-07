#include "tabela_hash.h"

int hash(int k)
{
    return k % N;
}

Aluno *hsh_get(Hash tab, int mat)
{
}

Aluno *hsh_set(Hash tab, int mat, char *n, char *e, char *t)
{
    int h = hash(mat);

    while (tab[h] != NULL)
    {
        if (tab[h]->matricula == mat)
            break;
        h = (h + 1) % N;
    }

    if (tab[h] == NULL)
    {
        tab[h] = (Aluno *)malloc(sizeof(Aluno));
        tab[h]->matricula = mat;
    }

    tab[h]->nome = n;
    tab[h]->turma = t;
    tab[h]->email = e;
}

void hsh_remove(Hash tab, int mat)
{
}

void hsh_imprime(Hash tab)
{
}
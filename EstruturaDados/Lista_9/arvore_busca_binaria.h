#include <stdio.h>
#include <stdlib.h>

struct arvbb
{
    int info;
    struct arvbb *esq;
    struct arvbb *dir;
};
typedef struct arvbb Arvbb;

Arvbb *arvbb_cria();
void arvbb_imprime(Arvbb *a);
Arvbb *arvbb_busca(Arvbb *r, int v);
Arvbb *arvbb_insere(Arvbb *a, int v);
Arvbb *arvbb_retira(Arvbb *a, int v);
void arvbb_imprime_decrescente(Arvbb *a);
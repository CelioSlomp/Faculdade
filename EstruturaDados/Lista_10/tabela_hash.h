#include <stdio.h>
#include <stdlib.h>

struct aluno
{
    int matricula;
    const char *nome;
    const char *turma;
    const char *email;
    struct aluno *prox;
};
typedef struct aluno Aluno;

#define N 127
typedef Aluno *Hash[N];

int hash(int k);
Aluno *hsh_get(Hash tab, int mat);
Aluno *hsh_set(Hash tab, int mat, char *n, char *e, char *t);
void hsh_remove(Hash tab, int mat);
void hsh_imprime(Hash tab);
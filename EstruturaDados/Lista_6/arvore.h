#include <stdio.h>
#include <stdlib.h>

struct NoArvoreBinaria
{
    int info;
    struct NoArvoreBinaria *sae;
    struct NoArvoreBinaria *sad;
};

typedef struct NoArvoreBinaria NoArvoreBinaria;

NoArvoreBinaria *criar();
NoArvoreBinaria *insere(int v, NoArvoreBinaria *sae, NoArvoreBinaria *sad);
int vazia(NoArvoreBinaria *raiz);
const char *toString(NoArvoreBinaria *raiz);
int pertence(NoArvoreBinaria *raiz, int v);
int pares(NoArvoreBinaria *raiz);
int folhas(NoArvoreBinaria *raiz);
void imprimePre(NoArvoreBinaria *raiz);
void imprimeSim(NoArvoreBinaria *raiz);
void imprimePos(NoArvoreBinaria *raiz);
int numNos(NoArvoreBinaria *raiz);
int altura(NoArvoreBinaria *raiz);
int igual(NoArvoreBinaria *raiz);
#include "arvore.h"

NoArvoreBinaria *criar()
{
    return NULL;
}

NoArvoreBinaria *insere(int v, NoArvoreBinaria *sae, NoArvoreBinaria *sad)
{
    NoArvoreBinaria *no = (NoArvoreBinaria *)malloc(sizeof(NoArvoreBinaria));
    no->info = v;
    no->sad = sad;
    no->sae = sae;
    return no;
}

int vazia(NoArvoreBinaria *raiz)
{
    return raiz == NULL;
}

const char *toString(NoArvoreBinaria *raiz) {}

int pertence(NoArvoreBinaria *raiz, int v)
{
    if (raiz == NULL)
        return 0;
    return (raiz->info == v) || pertence(raiz->sae, v) || pertence(raiz->sad, v);
}

int pares(NoArvoreBinaria *raiz)
{
    int val = 0;
    if (raiz == NULL)
        return 0;
    if (raiz->info % 2 == 0)
        val++;
    return pares(raiz->sad) + val + pares(raiz->sae);
}

int folhas(NoArvoreBinaria *raiz) {}

void imprimePre(NoArvoreBinaria *raiz)
{
    printf("<");
    if (raiz != NULL)
    {
        printf("%d", raiz->info);
        imprimePre(raiz->sae);
        imprimePre(raiz->sad);
    }
    printf(">");
}

void imprimeSim(NoArvoreBinaria *raiz) {}

void imprimePos(NoArvoreBinaria *raiz) {}

int numNos(NoArvoreBinaria *raiz) {}

int altura(NoArvoreBinaria *raiz) {}

int igual(NoArvoreBinaria *raiz) {}
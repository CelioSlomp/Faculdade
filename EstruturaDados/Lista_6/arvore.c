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

const char *toString(NoArvoreBinaria *raiz)
{
    char *str = (char *)malloc(sizeof(char) * numNos(raiz) * 10);
    char *str2 = str;
    str += sprintf(str, "<");
    if (raiz != NULL)
    {
        str += sprintf(str, "%d", raiz->info);
        str += sprintf(str, "%s", toString(raiz->sae));
        str += sprintf(str, "%s", toString(raiz->sad));
    }
    str += sprintf(str, ">");
    return str2;
}

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

int folhas(NoArvoreBinaria *raiz)
{
    int val = 0;
    if (raiz == NULL)
        return 0;
    if (raiz->sad == NULL && raiz->sae == NULL)
        val++;
    return folhas(raiz->sad) + val + folhas(raiz->sae);
}

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

void imprimeSim(NoArvoreBinaria *raiz)
{
    printf("<");
    if (raiz != NULL)
    {
        imprimeSim(raiz->sae);
        printf("%d", raiz->info);
        imprimeSim(raiz->sad);
    }
    printf(">");
}

void imprimePos(NoArvoreBinaria *raiz)
{
    printf("<");
    if (raiz != NULL)
    {
        imprimePos(raiz->sae);
        imprimePos(raiz->sad);
        printf("%d", raiz->info);
    }
    printf(">");
}

int numNos(NoArvoreBinaria *raiz)
{
    if (raiz == NULL)
        return 0;
    if (raiz->sad == NULL && raiz->sae == NULL)
        return 1;
    return numNos(raiz->sad) + numNos(raiz->sae) + 1;
}

int altura(NoArvoreBinaria *raiz)
{
    if (raiz == NULL || (raiz->sad == NULL && raiz->sae == NULL))
        return 0;
    int v1 = altura(raiz->sae) + 1;
    int v2 = altura(raiz->sad) + 1;
    if (v1 > v2)
        return v1;
    return v2;
}

int igual(NoArvoreBinaria *raiz1, NoArvoreBinaria *raiz2)
{
    if (raiz1 == NULL && raiz2 == NULL)
        return 1;
    if (raiz1 == NULL || raiz2 == NULL || (raiz1->info != raiz2->info))
        return 0;
    int esq = igual(raiz1->sae, raiz2->sae);
    int dir = igual(raiz1->sad, raiz2->sad);
    if (dir == 1 && esq == 1)
        return 1;
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct NoArvoreBinaria
{
    int info;
    struct NoArvoreBinaria *sae;
    struct NoArvoreBinaria *sad;
};

typedef struct NoArvoreBinaria NoArvoreBinaria;

NoArvoreBinaria *criar();                                                   // Feito
NoArvoreBinaria *insere(int v, NoArvoreBinaria *sae, NoArvoreBinaria *sad); // Feito
int vazia(NoArvoreBinaria *raiz);                                           // Feito
const char *toString(NoArvoreBinaria *raiz);                                // Feito
int pertence(NoArvoreBinaria *raiz, int v);                                 // Feito
int pares(NoArvoreBinaria *raiz);                                           // Feito
int folhas(NoArvoreBinaria *raiz);                                          // Feito
void imprimePre(NoArvoreBinaria *raiz);                                     // Feito
void imprimeSim(NoArvoreBinaria *raiz);                                     // Feito
void imprimePos(NoArvoreBinaria *raiz);                                     // Feito
int numNos(NoArvoreBinaria *raiz);                                          // Feito
int altura(NoArvoreBinaria *raiz);                                          // Feito
int igual(NoArvoreBinaria *raiz1, NoArvoreBinaria *raiz2);
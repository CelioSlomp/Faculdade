#include "arvore.h"

void main(void)
{
    NoArvoreBinaria *raiz = criar();

    // printf("%d", vazia(raiz));

    raiz = insere(1,
                  insere(2,
                         NULL,
                         insere(4, NULL, NULL)),
                  insere(3,

                         insere(5, NULL, NULL),
                         insere(6, NULL, NULL))

    );

    // printf("%d", pertence(raiz, 1));

    printf("%d", pares(raiz));

    // NoArvoreBinaria *raiz2 = cria();
    // NoArvoreBinaria *no6 = insere(6, NULL, NULL);
    // NoArvoreBinaria *no5 = insere(5, NULL, NULL);
    // NoArvoreBinaria *no3 = insere(3, no5, no6);

    // imprimePre(raiz);

    printf("\n");
}

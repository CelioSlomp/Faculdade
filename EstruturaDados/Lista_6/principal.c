#include "arvore.h"

void main(void)
{
       NoArvoreBinaria *raiz = criar();
       NoArvoreBinaria *raiz2 = criar();

       // printf("%d", vazia(raiz));

       raiz = insere(1,
                     insere(2,
                            NULL,
                            insere(4, NULL, NULL)),
                     insere(3,

                            insere(5, insere(7, NULL, NULL), NULL),
                            insere(6, NULL, NULL))

       );
       raiz2 = insere(1,
                      insere(2,
                             NULL,
                             insere(4, NULL, NULL)),
                      insere(3,

                             insere(5, NULL, NULL),
                             insere(6, NULL, NULL))

       );

       // printf("%d", pertence(raiz, 1));

       // Pares da arvore
       // printf("%d", pares(raiz));

       // Folhas da arvore
       // printf("%d", folhas(raiz));

       // Numero de nós
       // printf("%d", numNos(raiz));

       // Altura da arvore
       // printf("%d", altura(raiz));

       // NoArvoreBinaria *raiz2 = cria();
       // NoArvoreBinaria *no6 = insere(6, NULL, NULL);
       // NoArvoreBinaria *no5 = insere(5, NULL, NULL);
       // NoArvoreBinaria *no3 = insere(3, no5, no6);

       // imprimePre(raiz);
       //  imprimeSim(raiz);
       //  imprimePos(raiz);

       // Retorna um array de char da arvore
       // printf("\n%s", toString(raiz));

       // Verifica se é igual
       // printf("%d", igual(raiz, raiz2));
}
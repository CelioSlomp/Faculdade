#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    FilaVetor *fila = criar(10);
    FilaVetor *fila2 = criar(5);

    // Adiciona os itens à fila
    enqueue(fila, 1);
    enqueue(fila2, 2);
    enqueue(fila, 3);
    enqueue(fila2, 4);
    enqueue(fila, 5);
    enqueue(fila2, 6);

    // Retira o item

    // printf("\n%d", dequeue(fila));
    // printf("\n%d", dequeue(fila));

    // Verifica se a fila está vazia
    // printf("\nA fila está vazia? %d", isEmpty(fila));

    // Reseta a lista
    // reset(fila);
    // printf("\nA fila está vazia? %d", isEmpty(fila));

    // printa a fila inteira
    // printf("a fila: %s", toString(fila));

    // Concatena as duas filas
    // FilaVetor *a = concatena(fila, fila2);
    // printf("a fila: %s", toString(a));

    // Da merge nas duas primeiras filas
    // FilaVetor *a = merge(fila, fila2);
    // printf("\nA fila: %s", toString(a));
    // printf("\nA fila: %s", toString(fila));
    // printf("\nA fila: %s", toString(fila2));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "fila.c"

int main()
{
    FilaVetor *fila = criar(10);

    enqueue(fila, 1);
    enqueue(fila, 2);

    printf("%d", dequeue(fila));

    printf("\n%d", dequeue(fila));
    printf("\n%d", dequeue(fila));
    return 0;
}
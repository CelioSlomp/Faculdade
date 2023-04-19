#include <stdio.h>
#include <stdlib.h>

struct FilaVetor
{
    int tam;
    int n;
    int ini;
    int *vet;
};

typedef struct FilaVetor FilaVetor;

FilaVetor *criar();
void enqueue(FilaVetor *inic, int v);
int dequeue(FilaVetor *inic);
const char *toString(FilaVetor *inic);
int isEmpty(FilaVetor *inic);
void reset(FilaVetor *inic);
FilaVetor *concatena(FilaVetor *f1, FilaVetor *f2);
FilaVetor *merge(FilaVetor *f1, FilaVetor *f2);
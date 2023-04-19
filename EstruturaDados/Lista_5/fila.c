#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

FilaVetor *criar(int tamanho)
{
    FilaVetor *fila = (FilaVetor *)malloc(sizeof(FilaVetor));
    fila->tam = tamanho;
    fila->n = 0;
    fila->ini = 0;
    fila->vet = (int *)malloc(sizeof(int) * tamanho);
    return fila;
}

void enqueue(FilaVetor *inic, int v)
{
    // Pega o indice final da lista
    int fim = (inic->ini + inic->n) % inic->tam;
    if (inic->n != inic->tam)
    {
        // caso a quantidade de elementos seja diferente do tamanho
        // maximo da lista, adicionará o item, caso contrário
        // irá imprimir mensagem de erro.
        inic->vet[fim] = v;
        inic->n++;
    }
    else
        printf("Lista já está cheia. Item não adicionado");
}

int dequeue(FilaVetor *inic)
{
    if (inic->n != 0)
    {
        // Irá pegar o item do indice inicial
        int v = inic->vet[inic->ini];
        // Irá enderecar o novo inicio
        inic->ini = (inic->ini + 1) % inic->tam;
        // diminui o tamanho da lista
        inic->n--;
        return v;
    }
    else
    {
        // Caso esteja vazia, retornará 0.
        printf("Lista está vazia.");
        return 0;
    }
}

const char *toString(FilaVetor *inic) {}
int isEmpty(FilaVetor *inic) {}
void reset(FilaVetor *inic) {}
FilaVetor *concatena(FilaVetor *f1, FilaVetor *f2) {}
FilaVetor *merge(FilaVetor *f1, FilaVetor *f2) {}
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
        printf("\nLista está vazia.");
        return 0;
    }
}

const char *toString(FilaVetor *inic)
{
    // Ponteiro str (string principal)
    // Ponteiro str2 (ponteiro para o inicio de str)
    char *str = (char *)malloc(sizeof(char) * inic->n * 10);
    char *str2 = str;
    // cont conta quantos elementos tem a fila no while
    int cont = 0;
    // t pega o inicio da fila
    int t = inic->ini;
    while (cont < inic->n)
    {
        // sprintf concatena o char em str
        str += sprintf(str, "%d ", inic->vet[t]);
        t = (t + 1) % inic->tam;
        cont++;
    }
    return str2;
}

int isEmpty(FilaVetor *inic)
{
    // Retorna o valor booleano do tamanho igual a zero.
    return (inic->n == 0);
}

void reset(FilaVetor *inic)
{
    // o inicio é em 0 e o tamanho atual (n) é 0 também.
    inic->ini = 0;
    inic->n = 0;
}

FilaVetor *concatena(FilaVetor *f1, FilaVetor *f2)
{
    // Cria uma outra fila e o tamanho dela e a soma das duas passadas
    // por parâmetro.
    FilaVetor *f3 = criar(f1->tam + f2->tam);
    int cont = 0;
    // Pega o inicio e percorre toda a fila e vai adicionando
    // na nova lista.
    int t = f1->ini;
    while (cont < f1->n)
    {
        enqueue(f3, f1->vet[t]);
        t = (t + 1) % f1->tam;
        cont++;
    }
    cont = 0;
    // Faz a mesma coisa que o while anterior
    t = f2->ini;
    while (cont < f2->n)
    {
        enqueue(f3, f2->vet[t]);
        t = (t + 1) % f2->tam;
        cont++;
    }
    // Retorna a fila 3
    return f3;
}

FilaVetor *merge(FilaVetor *f1, FilaVetor *f2)
{
    // Cria a fila 3
    FilaVetor *f3 = criar(f1->tam + f2->tam);

    // Pega o inicio das 2 filas e cria um contador
    int cont = 0;
    int t1 = f1->ini;
    int t2 = f2->ini;
    // enquanto contador for menor que f1 ou f2
    // da enqueue na f3 o indice do vetor
    while (cont < f1->n || cont < f2->n)
    {
        if (cont < f1->n)
        {
            enqueue(f3, f1->vet[t1]);
            t1 = (t1 + 1) % f1->tam;
        }
        if (cont < f2->n)
        {
            enqueue(f3, f2->vet[t2]);
            t2 = (t2 + 1) % f2->tam;
        }
        cont++;
    }
    // Retorna f3
    return f3;
}
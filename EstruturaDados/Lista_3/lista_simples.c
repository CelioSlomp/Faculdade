#include <stdio.h>
#include <stdlib.h>
#include "lista_simples.h"

// Implementação das funções da lista 1
NoLista *sllCria(void)
{
    NoLista *lista = malloc(sizeof(NoLista));
    lista->prox = NULL;
    return lista;
}

NoLista *sllInsere(NoLista *head, int v)
{
    NoLista *no = sllCria();
    no->info = v;
    no->prox = head;
    return no;
}

void sllImprime(NoLista *head)
{
    NoLista *no = head;
    while (no->prox != NULL)
    {
        printf("%.0f ", no->info);
        no = no->prox;
    }
    printf("\n");
}

int sllVazia(NoLista *head)
{
    if (head->prox == NULL)
        return 1;
    else
        return 0;
}

NoLista *sllBusca(NoLista *head, int v)
{
    NoLista *no = head;
    while (1)
    {
        if (no->info == v)
            return no;
        if (no->prox == NULL && no->info != v)
            return NULL;
        else
            no = no->prox;
    }
}

int sllComprimento(NoLista *head)
{
    NoLista *no = head;
    int num = 0;
    while (1)
    {
        if (no->prox == NULL)
            return num;
        no = no->prox;
        num++;
    }
}

NoLista *sllUltimo(NoLista *head)
{
    NoLista *no = head;
    while (1)
    {
        if (no->prox->prox == NULL)
            return no;
        else
            no = no->prox;
    }
}

// Implementação das funções da lista 2
NoLista *sllRetira(NoLista *head, int v)
{
}

void sllLibera(NoLista *head)
{
}

NoLista *sllInsereFim(NoLista *head, int v)
{
}

int sllIgual(NoLista *lista1, NoLista *lista2)
{
}

void sllImprimeRecursivo(NoLista *head)
{
}

NoLista *sllRetiraRecursivo(NoLista *head, int v)
{
}

int sllComprimentoRecursivo(NoLista *head)
{
}

NoLista *sllIgualRecursivo()
{
}

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
    NoLista *atual = head;
    NoLista *proximo;
    while (1)
    {
        if (atual->info == v)
        {
            proximo = atual->prox;
            free(atual);
            return proximo;
        }
        if (atual->prox->info == v)
        {
            proximo = atual->prox->prox;
            free(atual->prox);
            atual->prox = proximo;
            return head;
        }
        if (atual->prox == NULL)
            return head;
        atual = atual->prox;
    }
}

void sllLibera(NoLista *head)
{
    NoLista *no = head;

    while (1)
    {
        if (no->prox->prox == NULL)
        {
            free(no->prox);
            no->prox = NULL;
            no = head;
        }
        else
        {
            no = no->prox;
        }
        if (head->prox == NULL)
        {
            break;
        }
    }
}

NoLista *sllInsereFim(NoLista *head, int v)
{
    NoLista *no = head;
    NoLista *no2 = no;
    while (1)
    {
        if (no->prox == NULL)
        {
            no->prox = sllCria();
            no->info = v;
            return no2;
        }
        else
            no = no->prox;
    }
}

int sllIgual(NoLista *lista1, NoLista *lista2)
{
    // As duas listas do passadas
    NoLista *no1 = lista1;
    NoLista *no2 = lista2;

    while (no1->prox != NULL && no2->prox != NULL)
    {
        if (no1->info != no2->info)
        {
            // Caso o conteúdo seja diferente, retorna 0
            return 0;
        }
        no1 = no1->prox;
        no2 = no2->prox;
    }
    // Verifica o tamanho das listas
    if (no1->prox == NULL && no2->prox == NULL)
        return 1;
    else
        return 0;
}

void sllImprimeRecursivo(NoLista *head)
{
    NoLista *no = head;
    if (no->prox != NULL)
    {
        printf("%.0f ", no->info);
        sllImprimeRecursivo(no->prox);
    }
}

NoLista *sllRetiraRecursivo(NoLista *head, int v)
{
    NoLista *no = head;
    NoLista *no1 = head->prox->prox;

    if (no->prox->info == v)
    {
        free(no->prox);
        no->prox = no1;
        return no;
    }
    no = sllRetiraRecursivo(no->prox, v);
    return no;
}

int sllComprimentoRecursivo(NoLista *head)
{
    NoLista *no = head;
    if (no->prox == NULL)
        return 0;
    else
        return 1 + sllComprimentoRecursivo(no->prox);
}

int sllIgualRecursivo(NoLista *lista1, NoLista *lista2)
{
    NoLista *no1 = lista1;
    NoLista *no2 = lista2;

    if (no1->info != no2->info)
        return 0;
    else
    {
        if (no1->prox == NULL && no2->prox == NULL)
            return 1;
        return sllIgualRecursivo(no1->prox, no2->prox);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

NoListaDupla *dllCria(void)
{
    return NULL;
}

NoListaDupla *dllInsere(NoListaDupla *head, int v)
{
    // aloca memoria e troca o valor do item.
    NoListaDupla *no = (NoListaDupla *)malloc(sizeof(NoListaDupla));
    no->ant = NULL;
    no->info = v;
    no->prox = head;
    if (head != NULL)
        head->ant = no;
    return no;
}

void dllImprime(NoListaDupla *head)
{
    NoListaDupla *no = head;
    // Percorre a lista toda e imprime os itens da lista.
    while (no != NULL)
    {
        printf("%.0f ", no->info);
        no = no->prox;
    }
    printf("\n");
}

int dllVazia(NoListaDupla *head)
{
    // Caso a cabeca seja nula, a lista esta vazia.
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

NoListaDupla *dllBusca(NoListaDupla *head, int v)
{
    NoListaDupla *no = head;
    while (no->info != v)
    {
        if (no == NULL)
            return NULL;
        no = no->prox;
    } // while
    if (no->info == v)
    {
        return no;
    }
}

int dllComprimento(NoListaDupla *head)
{
    NoListaDupla *no = head;
    int cont = 0;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

NoListaDupla *dllUltimo(NoListaDupla *head)
{
    NoListaDupla *no = head;
    if (no == NULL)
        return no;

    while (no->prox != NULL)
    {
        no = no->prox;
    }
    // Retorna o anterior pelo fato do while chegar até o valor NULL
    // portanto, retorna o valor anterior ao NULL.
    return no;
}

NoListaDupla *dllRetira(NoListaDupla *head, int v)
{
    NoListaDupla *temp;

    NoListaDupla *no = head;
    while (no->info != v)
    {
        no = no->prox;
        if (no == NULL)
        {
            return head;
        }
    }
    temp = no->prox;
    no = no->ant;
    free(no->prox);
    no->prox = temp;
    no->prox->ant = no;
    return head;
}

void dllLibera(NoListaDupla *head)
{
    NoListaDupla *no = head;
    // Não está funcionando direito
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
            head->prox = NULL;
            break;
        }
    }
}

NoListaDupla *dllInsereFim(NoListaDupla *head, int v)
{
    NoListaDupla *no = head;
    // Chega até o final da lista
    while (no->prox != NULL)
    {
        no = no->prox;
    }

    // Aloca a memoria em um elemento após o ultimo elemento e insere o valor.
    no->prox = (NoListaDupla *)malloc(sizeof(NoListaDupla));
    no->prox->info = v;
    no->prox->ant = no;
    no->prox->prox = NULL;
    return head;
}

int dllIgual(NoListaDupla *lista1, NoListaDupla *lista2)
{
    // Vai até o final da lista
    while (lista1 != NULL && lista2 != NULL)
    {
        // Caso seja diferente algum elemento retorna 0
        if (lista1->info != lista2->info)
            return 0;
        // Passa para o proximo elemento
        lista1 = lista1->prox;
        lista2 = lista2->prox;
    }

    // Retorna 1 caso sejam nulas
    if (lista1 == NULL && lista2 == NULL)
    {
        return 1;
    }
    return 0;
}

NoListaDupla *dllMerge(NoListaDupla *l1, NoListaDupla *l2)
{
    NoListaDupla *no = (NoListaDupla *)malloc(sizeof(NoListaDupla));
    NoListaDupla *tmp;
    no->ant = NULL;

    // Enquanto a lista 1 ou a lista 2 não for nula ele irá rodar
    while (l1 != NULL || l2 != NULL)
    {
        // Se l1 e l2 for diferente de nulo ele entra
        if (l1 != NULL)
        {
            // no prox recebe l1 e tmp recebe o nó para poder colocar
            // no anterior.
            no->prox = l1;
            l1 = l1->prox;
            tmp = no;
            no = no->prox;
            no->ant = tmp;
        }
        if (l2 != NULL)
        {
            no->prox = l2;
            l2 = l2->prox;
            tmp = no;
            no = no->prox;
            no->ant = tmp;
        }
    }
    // Volta para o inicio da lista
    while (no->ant != NULL)
    {
        no = no->ant;
    }
    tmp = no;
    no = no->prox;
    no->ant = NULL;
    // Libera a tmp anterior
    free(tmp);
    return no;
}
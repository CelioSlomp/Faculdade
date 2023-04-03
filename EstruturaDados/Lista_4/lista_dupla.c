#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

NoListaDupla *dllCria(void)
{
    // Aloca a memoria do struct
    NoListaDupla *lista = malloc(sizeof(NoListaDupla));
    lista->ant = NULL;
    lista->prox = NULL;
    return lista;
}

NoListaDupla *dllInsere(NoListaDupla *head, int v)
{
    NoListaDupla *no = dllCria();
    no->ant = NULL;
    no->info = v;
    no->prox = head;
    head->ant = no;
    return no;
}

void dllImprime(NoListaDupla *head)
{
    NoListaDupla *no = head;
    while (no->prox != NULL)
    {
        printf("%.0f ", no->info);
        no = no->prox;
    }
    printf("\n");
}

int dllVazia(NoListaDupla *head)
{
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
    int cont = -1;
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
    return no->ant;
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
    NoListaDupla *tmp;
    while (no->prox != NULL)
    {
        no = no->prox;
        tmp = no->ant;
        tmp->ant = NULL;
        tmp->prox = NULL;
        free(tmp);
    }
}

NoListaDupla *dllInsereFim(NoListaDupla *head, int v)
{
}
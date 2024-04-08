#include <stdio.h>
#include <stdlib.h>

struct noLista
{
    float info;
    struct noLista *prox;
};
typedef struct noLista NoLista;

NoLista *cria(void)
{
    NoLista *lista = NULL;
    return lista;
}

NoLista *insere(NoLista *head, int v)
{
    NoLista *no = malloc(sizeof(NoLista));
    no->info = v;
    no->prox = head;
    return no;
}

int pertence(NoLista *head, int v)
{
    NoLista *no = head;
    while (no != NULL)
    {

        if (no->info == v)
            return 1;
        no = no->prox;
    }
    return 0;
}

int main()
{
    NoLista *h = cria();
    int numero;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &numero);
        h = insere(h, numero);
    }
    printf("Digite o numero que queira procurar: ");
    scanf("%d", &numero);

    if (pertence(h, numero))
        printf("O número %d pertence.", numero);
    else
    {
        printf("O número %d nao pertence.", numero);
    }
    return 0;
}
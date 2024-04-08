#include <stdio.h>
#include <time.h>
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

int verifPrimo(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    NoLista *h = cria();

    srand(time(NULL));
    int numPrimos = 0;
    int contador = 0;
    int r;

    while (numPrimos < 25)
    {
        r = rand() % 100 + 1;
        if (verifPrimo(r))
        {
            if (!pertence(h, r))
            {
                h = insere(h, r);
                numPrimos++;
            }
        }
        contador++;
    }

    printf("Numeros gerados: %d\n", contador);

    return 0;
}
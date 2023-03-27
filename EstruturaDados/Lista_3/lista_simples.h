#include <stdio.h>

struct noLista
{
    float info;
    struct noLista *prox;
};
typedef struct noLista NoLista;

// Itens da Lista 2
NoLista *sllCria(void);
NoLista *sllInsere(NoLista *head, int v);
void sllImprime(NoLista *head);
int sllVazia(NoLista *head);
NoLista *sllBusca(NoLista *head, int v);
int sllComprimento(NoLista *head);
NoLista *sllUltimo();

// Itens da Lista 3
NoLista *sllRetira(NoLista *head, int v);
void sllLibera(NoLista *head);
NoLista *sllInsereFim(NoLista *head, int v);
int sllIgual(NoLista *lista1, NoLista *lista2);
void sllImprimeRecursivo(NoLista *head);
NoLista *sllRetiraRecursivo(NoLista *head, int v);
int sllComprimentoRecursivo(NoLista *head);
int sllIgualRecursivo(NoLista *lista1, NoLista *lista2);
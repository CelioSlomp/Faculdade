#include <stdio.h>

struct NoListaDupla
{
    float info;
    struct NoListaDupla *ant;
    struct NoListaDupla *prox;
};

typedef struct NoListaDupla NoListaDupla;

NoListaDupla *dllCria(void);                        // Feito
NoListaDupla *dllInsere(NoListaDupla *head, int v); // Feito
void dllImprime(NoListaDupla *head);                // Feito
int dllVazia(NoListaDupla *head);                   // Feito
NoListaDupla *dllBusca(NoListaDupla *head, int v);  // Feito
int dllComprimento(NoListaDupla *head);             // Feito
NoListaDupla *dllUltimo();                          // Feito
NoListaDupla *dllRetira(NoListaDupla *head, int v); // Feito
void dllLibera(NoListaDupla *head);                 // Feito
NoListaDupla *dllInsereFim(NoListaDupla *head, int v);
int sllIgual(NoListaDupla *lista1, NoListaDupla *lista2);
NoListaDupla sllMerge(NoListaDupla *l1, NoListaDupla *l2);
#include <stdio.h>
#include <stdlib.h>

/* tipo abstrato de dados Arvv */
struct arvv
{
    int info;
    struct arvv *prim;
    struct arvv *prox;
};
typedef struct arvv Arvv;

/* prot ́otipos das funcoes para operacoes nas arvores */
Arvv *arvv_cria(int v);              // Feito
void arvv_insere(Arvv *a, Arvv *sa); // Feito
Arvv *arvv_libera(Arvv *a);          // Feito
int arvv_pertence(Arvv *a, int n);   // Feito
void arvv_imprime(Arvv *a);          // Feito
int arvv_altura(Arvv *a);            // Feito
int arvv_pares(Arvv *a);             // Feito
int arvv_folhas(Arvv *a);
int arvv_igual(Arvv *a1, Arvv *a2);
Arvv *arvv_copia(Arvv *a);
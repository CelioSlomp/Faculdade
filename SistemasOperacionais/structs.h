#include<stdio.h>

struct filaPrioridade
{
    int prioridade;
    int valor;
    struct filaPrioridade *prox;
};
typedef struct filaPrioridade filaPrioridade;

void adicionarItem(filaPrioridade *no, int val, int prio);
void removerItem(int val);
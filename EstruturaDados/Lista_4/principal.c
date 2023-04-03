#include <stdio.h>
#include "lista_dupla.c"

int main()
{
    // Criar a lista e inserir itens à lista.
    NoListaDupla *teste = dllCria();
    teste = dllInsere(teste, 3);
    teste = dllInsere(teste, 2);
    teste = dllInsere(teste, 1);
    teste = dllInsere(teste, 2);
    teste = dllInsere(teste, 3);
    teste = dllInsere(teste, 6);
    teste = dllInsere(teste, 5);
    teste = dllInsere(teste, 4);
    teste = dllInsere(teste, 1);

    // Imprimir toda lista
    // dllImprime(teste);

    // Verificar se está vazia
    // printf("%d", dllVazia(teste->prox));

    // Buscar item
    // teste = dllBusca(teste, 2);
    // printf("%.0f", teste->info);

    // Comprimento
    // printf("A lista tem: %d elementos.", dllComprimento(teste));

    // Ultimo elemento
    // teste = dllUltimo(teste);
    // printf("%.0f", teste->info);

    // Retira elemento
    // teste = dllRetira(teste, 5);
    // dllImprime(teste);

    // Limpa a lista;
    // dllLibera(teste);
    // dllImprime(teste);

    return 0;
}
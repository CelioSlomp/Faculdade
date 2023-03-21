#include <stdio.h>
#include "lista_simples.c"

int main()
{
    // Cria a lista
    NoLista *teste = sllCria();

    // Insere um elemento na lista
    teste = sllInsere(teste, 3);
    teste = sllInsere(teste, 7);
    teste = sllInsere(teste, 5);
    teste = sllInsere(teste, 4);
    teste = sllInsere(teste, 2);
    teste = sllInsere(teste, 8);
    teste = sllInsere(teste, 4);
    teste = sllInsere(teste, 5);

    // retorna o tamanho da lista
    printf("\nTamanho da lista: %d", sllComprimento(teste));

    // Imprime os elementos da lista
    printf("\nElementos da lista: ");
    sllImprime(teste);

    // Verifica se está vazia
    printf("\nÉ vazia? %d", sllVazia(teste));

    // Busca pelo valor 3
    teste = sllBusca(teste, 3);

    // Pega o ultimo elemento da lista
    teste = sllUltimo(teste);
    printf("\nUltimo elemento: %.0f", teste->info);
}
#include <stdio.h>
#include "lista_simples.c"

int main()
{
    // Cria a lista
    NoLista *teste = sllCria();
    NoLista *teste1 = sllCria();

    // Insere alguns elementos na lista
    teste = sllInsere(teste, 3);
    teste = sllInsere(teste, 7);
    teste = sllInsere(teste, 5);
    teste = sllInsere(teste, 4);
    teste = sllInsere(teste, 2);
    teste = sllInsere(teste, 8);
    teste = sllInsere(teste, 4);
    teste = sllInsere(teste, 5);

    // Testes de implementação da lista 1

    // retorna o tamanho da lista
    // printf("\nTamanho da lista: %d", sllComprimento(teste));

    // Imprime os elementos da lista
    // printf("\nElementos da lista: ");
    // sllImprime(teste);

    // Verifica se está vazia
    // printf("\nÉ vazia? %d", sllVazia(teste));

    // Busca pelo valor 3
    // teste = sllBusca(teste, 3);

    // Pega o ultimo elemento da lista
    // teste = sllUltimo(teste);
    // printf("\nUltimo elemento: %.0f", teste->info);

    // Testes de implementação da lista 2

    // Insere no final da lista
    teste = sllInsereFim(teste, 2);
    printf("\nElementos da lista: ");
    sllImprime(teste);

    // Verifica se são iguais
    // teste1 = sllInsere(teste1, 4);
    // printf("As listas são iguais? %d", sllIgual(teste, teste));

    // Imprime recursivo
    // printf("\nElementos da lista: ");
    // sllImprimeRecursivo(teste);

    // Verifica se é igual recursivamente
    // teste1 = sllInsere(teste1, 4);
    // printf("As listas são iguais? %d", sllIgualRecursivo(teste1, teste));

    // Comprimento recursivo
    // printf("o tamanho é: %d ", sllComprimentoRecursivo(teste));

    // Retira elemento da lista
    teste = sllRetira(teste, 2);
    printf("\nElementos da lista: ");
    sllImprimeRecursivo(teste);

    // Apaga a lista
    // sllLibera(teste);
    // printf("\nElementos da lista: ");
    // sllImprimeRecursivo(teste);

    // Remove Recursivo
    teste = sllRetiraRecursivo(teste, 4);
    printf("\nElementos da lista: ");
    sllImprimeRecursivo(teste);
}
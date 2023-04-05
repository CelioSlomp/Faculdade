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
    teste = dllInsere(teste, 3);
    teste = dllInsere(teste, 8);

    NoListaDupla *teste1 = dllCria();
    teste1 = dllInsere(teste1, 3);
    teste1 = dllInsere(teste1, 6);
    teste1 = dllInsere(teste1, 8);
    teste1 = dllInsere(teste1, 2);
    teste1 = dllInsere(teste1, 1);

    // Imprimir toda lista
    // dllImprime(teste);

    // Verificar se está vazia
    // printf("%d", dllVazia(teste->prox));

    // Buscar item
    // teste = dllBusca(teste, 123);
    // printf("%.0f", teste->info);

    // Comprimento
    // printf("A lista tem: %d elementos.", dllComprimento(teste));

    // Ultimo elemento
    // teste = dllUltimo(teste);
    // printf("%.0f", teste->info);

    // Retira elemento
    // dllImprime(teste);
    // teste = dllRetira(teste, 5);
    // dllImprime(teste);

    // Não está funcionando direito
    // Limpa a lista;
    // dllLibera(teste);
    // dllImprime(teste);

    // Insere no final da lista
    // teste = dllInsereFim(teste, 123);
    // dllImprime(teste);

    // Verifica se a lista é igual
    // printf("É igual? %d", dllIgual(teste, teste1));

    // Funcao dllMerge
    // teste = dllMerge(teste, teste1);
    // dllImprime(teste);

    return 0;
}

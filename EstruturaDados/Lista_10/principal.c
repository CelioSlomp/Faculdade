#include "tabela_hash.h"

int main()
{
    Hash tab[N];

    // funcao set
    hsh_set(tab, 200, "Brazil", "Sim", "Nao");
    hsh_set(tab, 327, "Abobora", "Sim", "Nao");
    hsh_set(tab, 32, "picole", "Sim", "Nao");
    hsh_set(tab, 37, "frango", "Sim", "Nao");
    hsh_set(tab, 347, "elefante", "Sim", "Nao");
    hsh_set(tab, 337, "jogo", "Sim", "Nao");
    hsh_set(tab, 129, "teclado", "Sim", "Nao");
    hsh_set(tab, 256, "Europa", "Sim", "Nao");
    hsh_set(tab, 383, "Pera", "Sim", "Nao");

    // Metodo get
    Aluno *al = hsh_get(tab, 129);
    printf("%s\n", al->nome);

    // Funcao imprime
    hsh_imprime(tab);
    printf("\n");

    // Funcao remove
    hsh_remove(tab, 891);
    hsh_imprime(tab);

    return 0;
}
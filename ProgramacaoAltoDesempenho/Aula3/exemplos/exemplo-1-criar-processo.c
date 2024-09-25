#include <stdio.h>
// Necessária por conter a definição de fork.
#include <unistd.h>
// Necessária por conter a definição o tipo pid_t, usado para armazenar o ID de um processo.
#include <sys/types.h>

int main() {
    pid_t pid; // Variável que armazena o ID do processo.

    // A função fork cria um novo processo.
    // Ela retorna um valor do tipo pid_t, que representa o ID do processo criado.
    pid = fork();

    // Verifica se o fork foi bem-sucedido.
    if (pid < 0) {
        // Ocorreu um erro ao criar o processo filho
        perror("Erro ao criar o processo");
        return 1;
    }
    else if (!pid) // É o processo filho?
        printf("Este é o processo filho! ID do processo: %d\n", getpid());
    else {  // É o processo pai.
        printf("Este é o processo pai! ID do processo: %d\n", getpid());
        // printf("ID do processo filho criado: %d\n", pid);
    }

    return 0;
}
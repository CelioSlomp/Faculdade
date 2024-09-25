#include <stdio.h>
// Necessária por conter a definição de fork.
#include <unistd.h>
// Necessária por conter a definição o tipo pid_t, usado para armazenar o ID de um processo.
#include <sys/types.h>
// Necessária por conter a definição de waitpid, usada para esperar pelo término de um processo filho específico ou de qualquer processo filho, dependendo dos parâmetros.
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2; // Variáveis que armazenam o ID dos seus respectivos processos.

    // Primeiro processo filho.
    pid1 = fork();

    if (pid1 < 0) {
        perror("Erro ao criar o primeiro processo filho");
        return 1;
    }
    else if (!pid1) {
        // Código do primeiro processo filho.
        printf("Este é o primeiro processo filho! PID do processo: %d\n", getpid());
        return 0; // O processo filho 1 termina aqui.
    }

    waitpid(pid1, NULL, 0); // Experimente comentar essa linha e descomentar a linha 50. Analise a diferença no resultado.

    // Processo pai continua aqui
    printf("Este é o processo pai! PID do processo: %d\n", getpid());

    // Segundo processo filho.
    pid2 = fork();

    if (pid2 < 0) {
        perror("Erro ao criar o segundo processo filho");
        return 1;
    }
    else if (!pid2) {
        // Código do segundo processo filho.
        printf("Este é o segundo processo filho! PID do processo: %d\n", getpid());
        return 0; // O processo filho 2 termina aqui.
    }

    // Processo pai continua aqui.
    printf("Este é o processo pai! PID do processo: %d\n", getpid());

    // Espera os processos filhos terminarem
    // Essas chamadas bloqueiam a execução do processo pai até que os processos filho terminem.
    // Quando os processos filho terminam, o processo pai continua a execução após essas linhas de código.
    // Dessa forma, sincronizamos a execução dos processos pai e filhos.
    // waitpid(pid1, NULL, 0); // Experimente comentar a linha 25 e descomentar esta linha. Analise a diferença no resultado.
    waitpid(pid2, NULL, 0);

    // Processo pai continua aqui.
    printf("Este é o processo pai! PID do processo: %d\n", getpid());

    return 0;
}

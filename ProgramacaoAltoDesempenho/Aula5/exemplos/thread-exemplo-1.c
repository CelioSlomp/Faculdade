#include <stdio.h>
#include <pthread.h>

// Função que será executada pela thread
void *countNumbers(void *arg) {
    for (int i = 1; i <= 10; i++) {
        printf("Thread contando: %d\n", i);
    }

    // Encerra a thread e retorna um valor (pode ser NULL nesse caso)
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_id;

    // Cria uma nova thread
    int status = pthread_create(&thread_id, NULL, countNumbers, NULL);

    if (status) { // Se o status for diferente de zero, temos um erro
        printf("Erro ao criar a thread!\n");
        return 1;
    }

    // Espera a thread terminar
    status = pthread_join(thread_id, NULL);

    if (status) { // Se o status for diferente de zero, temos um erro
        printf("Erro ao aguardar a thread!\n");
        return 1;
    }

    printf("Thread principal terminou.\n");
    return 0;
}

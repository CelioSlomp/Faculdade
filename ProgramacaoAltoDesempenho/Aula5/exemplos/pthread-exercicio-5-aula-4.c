#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_ITERATIONS 100

int variavelCompartilhada = 0;

void* incrementa(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++)
        variavelCompartilhada++;

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
        {pthread_create(&threads[i], NULL, incrementa, NULL);
        pthread_join(threads[i], NULL);
        }
    //for (int i = 0; i < NUM_THREADS; i++)

    printf("Valor final da variável compartilhada: %d\n", variavelCompartilhada);

    return 0;
}

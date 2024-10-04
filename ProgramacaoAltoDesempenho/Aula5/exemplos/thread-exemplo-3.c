#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum1 = 0; // Soma para a primeira metade
int sum2 = 0; // Soma para a segunda metade

// A primeira thread executará nesta função
void *runner1(void *param) {
    int i, upper = atoi(param) / 2;
    for (i = 1; i <= upper; i++)
        sum1 += i;
    pthread_exit(0);
}

// A segunda thread executará nesta função
void *runner2(void *param) {
    int i, lower = atoi(param) / 2 + 1;
    int upper = atoi(param);
    for (i = lower; i <= upper; i++)
        sum2 += i;
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    pthread_t tid1, tid2; // Identificadores das threads
    pthread_attr_t attr; // Conjunto de atributos das threads

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <valor inteiro>\n", argv[0]);
        return -1;
    }

    // Define os atributos padrão das threads
    pthread_attr_init(&attr);

    // Cria as threads
    pthread_create(&tid1, &attr, runner1, argv[1]);
    pthread_create(&tid2, &attr, runner2, argv[1]);

    // Espera pelas threads para encerrarem
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    int total_sum = sum1 + sum2;
    printf("Valor calculado pela primeira thread = %d\n", sum1);
    printf("Valor calculado pela segunda thread = %d\n", sum2);
    printf("Somatório total = %d\n", total_sum);

    return 0;
}
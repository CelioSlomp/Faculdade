// Exemplo do livro

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; // Dado compartilhado entre as threads

// A thread executará nesta função
void *runner(void *param) {
	int i, upper = atoi(param);
	sum = 0;
	for (i = 1; i <= upper; i++)
		sum += i;
	pthread_exit (0);
}

int main(int argc, char *argv[]) {
	pthread_t tid; // O identificador da thread
	pthread_attr_t attr; // Conjunto de atributos da thread

	// Define os atributos padrão da thread
	pthread_attr_init(&attr);
	// Cria a thread
	pthread_create(&tid, &attr, runner, argv[1]);
	// Espera pela thread para encerrar
	pthread_join (tid, NULL);
	
	printf("Somatório = %d\n", sum);
}
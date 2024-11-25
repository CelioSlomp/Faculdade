#include <stdio.h>
#define TAM 18
void main() {
	int meuVetor[TAM] = {81, 85, 69, 32, 68, 69, 83, 65, 70, 73, 79, 32, 76, 79, 85, 67, 79, 33};
	int i;

	for (i = 0; i < TAM; i++) {
		printf("%i", meuVetor[i]);
	}
	printf("\n");
	
	
	for (i = 0; i < TAM; i++) {
		printf("%c", meuVetor[i]);
	}
	printf("\n");
	
}

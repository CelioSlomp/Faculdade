#include <omp.h>
#include <stdio.h>

int main() {
	// Código sequencial
	#pragma omp parallel
	printf("Eu sou uma região paralela.\n");
	// Código sequencial
	return 0;
}
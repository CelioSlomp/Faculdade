#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYMBOLTABLESIZE 128
#define TEXTSIZE 64

char l[TEXTSIZE];
int currentEmptyPosition = 0;

struct symbol {
	int key;
	char id[TEXTSIZE];
} symbolTable[SYMBOLTABLESIZE];

void display(int a[SYMBOLTABLESIZE]) {

	if (currentEmptyPosition == 0) {
		printf("A tabela está vazia.\n");
		return;
	}

	int i;
	printf("\nTabela de símbolos:\nChaveHash ID");

	for (i = 0; i < currentEmptyPosition; i++)
		printf("\n%d\t %s", symbolTable[i].key, symbolTable[i].id);

	printf("\n");

}
 
void lprob(int a[SYMBOLTABLESIZE]) {

	if (currentEmptyPosition == SYMBOLTABLESIZE) {

		printf("\nA tabela Hash está cheia. Você não pode mais inserir identificadores.\n");
		display(a);

		return;

	}

	symbolTable[currentEmptyPosition].key = currentEmptyPosition;
	strcpy(symbolTable[currentEmptyPosition++].id, l);

}
 
void search() {

	char la[TEXTSIZE];
	int i;

	printf("Entre com o ID: ");
	scanf("%s", la);

	for (i = 0; i < currentEmptyPosition; i++) {
		if (strcmp(symbolTable[i].id, la) == 0) {
			printf("O identificador \"%s\" está na %dª linha da tabela de símbolos.\n", la, symbolTable[i].key + 1);
			return;
		}
	}

	printf("O identificador procurado não está na tabela de símbolos.\n");
}

int main() {

	int a[SYMBOLTABLESIZE];
	int ch;
	char ans;
	memset(a, 0, SYMBOLTABLESIZE);

	do {
		printf("\n* Tabela de símbolos *\n1 - Criar um símbolo na tabela.\n2 - Buscar um símbolo na tabela.\n3 - Imprimir a tabela de símbolos\n4 - Sair\n\n");
		scanf("%d", &ch);

		switch (ch) {
			case 1:
				do {
					printf("Informe o identificador: ");
					scanf("%s", l);
					lprob(a);
					printf("\nDeseja continuar criando símbolos na tabela (S/N)? ");
					scanf(" %c", &ans);
				} while (ans == 'S' || ans== 's');

				display(a);
				break;
			case 2:
				search();
				break;
			case 3:
				display(a);
				break;
			case 4:
				exit(0);
		}
	} while (1);

	return 0;
}
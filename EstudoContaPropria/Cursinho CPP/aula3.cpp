// Aula focada em variáveis e pouco de como utilizar o
// comando cout (print)

#include <iostream>
using namespace std;

int main(){
	cout << "Aula 3 do Cursinho de CPP pela W3C\n";

	// Variaveis são containers que armazenam dados.
	// Em c++ existem cinco tipos primitivos de va-
	// riáveis, são elas: 'int', 'double', 'char', 
	// 'string' e 'bool'.
	
	// Declarando variaveis:
	// tipo Nome_da_variavel = valor;
	// é igualzinho ao java.
	
	int numero = 5;
	double numeroVirgula = 4.99;
	char letra = 'S';
	string meuTexto = "Boa tarde";
	bool booleano = true;

	// Para printar é utilizado o comando cout
	// dentro dele precisa ter os << entre os
	// dados e variaveis, (é igual ao + em java)
	
	cout << "Número: " << numero
		<< " Virgula: " << numeroVirgula
		<< " Letra: " << letra
		<< " Texto: " << meuTexto
		<< " Booleano: " << booleano;

	// Para constantes é só colocar "const" antes do
	// tipo da variável.

	const int meuNumero = 15;
	cout << meuNumero;

	return 0;
}

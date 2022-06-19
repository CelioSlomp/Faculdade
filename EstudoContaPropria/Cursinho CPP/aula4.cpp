// Aula de input para C++
// juntamente com os tipos de dado

#include <iostream>
#include <string>
using namespace std;
int main(){

    // Em c++ é igual ao java na quebra de linha
    // então, tenho que escrever um cout e um cin
    // logo em seguida

    int x, y, soma;

    cout << "Escreva um numero: ";
    // Esta é a sintaxe básica para input.
    // o cin vem automaticamente com um \n.
    cin >> x;
    cout << "Escreva outro numero: ";
    cin >> y;
    soma = x + y;
    cout << "Soma é: "<< soma;

    // Tipos de dados
    
    /* 
    * Tipo booleano armazena 1 byte;
    * Tipo char armazena 1 byte;
    * Tipo inteiro armazena 2 a 4 bytes;
    * Tipo float armazena 4 bytes;
    * Tipo double armazena 8 bytes;
    */

    // para o char: ele também aceita valores da tabela ASCII
    char letra = 'B';
    char a = 65;
    char b = 66;
    // e por ai vai;

    // Para o tipo string, tem que dar include na biblioteca
    // string lá no inicio

    string oi = "\nOla";
    cout << oi;


    return 0;
}
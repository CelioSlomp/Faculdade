'''
Implementar uma calculadora com as seguintes funcionalidades: adição, subtração, multiplicação, divisão, exponenciação e raiz quadrada.

*  Especificar os casos de testes de unidade indicando:
 - Estado inicial
 - Entradas de teste
 - Condições de execução
 - Saídas esperadas.

*  Implementar os casos de testes
 -  Linguagem livre
 -  Entrega até o final da aula de 24/05
'''

class Calculadora:
    def __init__(self) -> None:
        print("Calculadora iniciada.")

    def adicao(self, *args):
        soma = 0
        for i in args:
            soma += i
        return soma
    
    def subtracao(self, num1, num2):
        return num1 - num2
    
    def multiplicacao(self, *args):
        pass
    

def main():
    calc = Calculadora()

    print(calc.adicao(0, 1, 2, 3))

if __name__ == "__main__":
    main()
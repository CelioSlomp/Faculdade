
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

    def adicao(self, *num, **kwarg):
        if kwarg == []:
            return num + 0
        return num + self.adicao(kwarg)
    

def main():
    calc = Calculadora()

    print(calc.adicao(1,2,3,4,5))

if __name__ == "__main__":
    main()
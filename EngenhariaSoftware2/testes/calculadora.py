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
    def adicao(self, args):
        soma = 0
        for i in args:
            if type(i) != float and type(i) != int:
                raise TypeError
            soma += i
        return soma
    
    def subtracao(self, numeros):
        for i in numeros:
            if type(i) != float and type(i) != int:
                raise TypeError
        return numeros[0] - numeros[1]
    
    def multiplicacao(self, args):
        mult = 1
        for i in args:
            if type(i) != float and type(i) != int:
                raise TypeError
            mult *= i
        return mult
    
    def divisao(self, numeros):
        for i in numeros:
            if type(i) != float and type(i) != int:
                raise TypeError
        if not numeros[1]:
            raise ZeroDivisionError("Divisao por 0")
        return numeros[0]/numeros[1]
    
    def exponenciacao(self, n):
        for i in n:
            if type(i) != float and type(i) != int:
                raise TypeError
        if n[0] < 0 and ((n[1] < 1 and n[1] > 0) or (n[1] < 0 and n[1] > -1)):
            raise ValueError("Não tem raiz. Valor negativo.")
        return n[0]**n[1]
    
    def raizQuadrada(self, num):
        if type(num) != float and type(num) != int:
            raise TypeError
        if num < 0:
            raise ValueError("Não tem raiz. Valor negativo.")
        return self.exponenciacao([num, 1/2])
    

def main():
    calc = Calculadora()

    x = 0
    while x != 7:
        print('--------------------------------')
        print('O que desejas fazer?')
        print('1 - Adicao. (Digite P para parar)')
        print('2 - Subtração.')
        print('3 - Multiplicacao. (Digite P para parar)')
        print('4 - Divisao.')
        print('5 - Exponenciação.')
        print('6 - Raiz Quadrada.')
        print('7 - Parar execução.')
    
        valorResult = "Nenhuma operação foi escolhida."
        x = int(input("Digite a operação: "))
        if x in [1, 3]:
            valores = []
            while 1:
                val = input("Digite o valor: ")
                try:
                    valores.append(float(val))
                except:
                    break
            
            if x == 1:
                valorResult = calc.adicao(valores)
            else:
                valorResult = calc.multiplicacao(valores)
        
        elif x == 6:
            valorResult = calc.raizQuadrada(int(input("Digite o valor: ")))

        elif x == 7:
            print("Parando a execução")
            break

        else:
            val1 = input("Digite o valor 1: ")
            val2 = input("Digite o valor 2: ")

            try:
                valores = [int(val1), int(val2)]    

                if x == 2:
                    valorResult = calc.subtracao(valores)
                
                elif x == 4:
                    valorResult = calc.divisao(valores)
                
                elif x == 5:
                    valorResult = calc.exponenciacao(valores)
            
            except:
                print("Valores inválidos.")
        
        print("")
        print("Valor resultante:", valorResult)         
        print("")

if __name__ == "__main__":
    main()
def main():
    numero = int(input("Digite um numero: "))
    if numprimo(numero):
        return "O numero é primo"
    else:
        return "O numero não é primo"

def numprimo(numero):
    for i in range(2, numero):
        if numero%i == 0:
            return False
    return True

if __name__ == "__main__":
    print(main())
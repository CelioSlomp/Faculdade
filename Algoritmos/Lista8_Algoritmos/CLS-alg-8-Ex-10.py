def main():
    listaDesc = []
    print("Digite os valores, caso acabe, nao insira nada e aperte enter.")
    while True:
        val1 = input("Digite um valor: ")
        if val1 == "":
            break
        val2 = int(input("Digite o numero: "))
        listaDesc.append(val1)
        listaDesc.append(val2)
    return decrunlenght(listaDesc)

    
def decrunlenght(li: list):
    pass

if __name__ == "__main__":
    print(main())
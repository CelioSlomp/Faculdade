def main():
    listaDesc = []
    print("Digite os valores, caso acabe, nao insira nada e aperte enter.")
    while True:
        val1 = input("Digite um valor: ")
        if val1 == "":
            break
        listaDesc.append(val1)
    return codrunlenght(listaDesc)

def codrunlenght(li: list):
    pass    

if __name__ == "__main__":
    print(main())
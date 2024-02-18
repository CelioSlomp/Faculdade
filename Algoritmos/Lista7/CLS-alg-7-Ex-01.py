def main():
    palavra = input("Digite uma palavra: ")
    return verpalavra(palavra)

def verpalavra(palavra):
    lista = []
    for i in palavra:
        lista.append(i)

    lista2 = set(lista)
    lista2 = list(lista2)
    lista.sort()
    lista2.sort()
    if lista == lista2:
        return True
    else:
        return False

if __name__ == "__main__":
    print(main())
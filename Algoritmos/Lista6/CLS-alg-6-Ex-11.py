from random import randint
def main():
    lista = []
    while len(lista) != 6:
        rand = randint(1, 60)
        if rand not in lista:
            lista.append(rand)
    lista.sort()
    numeros = ""
    for i in lista:
        numeros += str(i)
        if i != lista[-1]:
            numeros += " "
    return numeros

if __name__ == "__main__":
    print(main())
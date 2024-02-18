def main():
    lista = input("digite uma lista de numeros: ")
    numin = int(input("Digite um numer minimo: "))
    numax = int(input("Digite um numero maximo: "))
    return countRange(trad(lista), numin, numax)

def countRange(lista, numin, numax):
    cont = 0
    for i in lista:
        if i <= numin or i >= numax:
            cont += 1
    return cont

def trad(lista):
    lista = lista.split(" ")
    ind = 0
    for i in lista:
        lista[ind] = int(i)
        ind += 1
    return lista

if __name__ == "__main__":
    print(main())
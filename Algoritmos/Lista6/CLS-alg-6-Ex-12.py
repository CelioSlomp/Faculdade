def main():
    lista = input("Digite uma lista de numeros: ")
    outlis = trad(lista)
    cres = trad(lista)
    cres.sort()
    decr = trad(lista)
    decr.sort(reverse=True)
    if outlis == cres or outlis == decr:
        return True
    else:
        return False

def trad(lista):
    lista = lista.split(" ")
    ind = 0
    for i in lista:
        lista[ind] = int(i)
        ind += 1
    return lista


if __name__ == "__main__":
    print(main())
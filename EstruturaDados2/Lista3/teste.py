def main():
    lista = ['3','4','5','2','1','7','0']


    indi = 0
    for i in lista:
        ind = 0
        for j in lista:
            if lista[ind] > lista[indi]:
                lista[indi], lista[ind] = lista[ind], lista[indi]
            ind += 1
        indi += 1


    print(lista)

if __name__ == "__main__":
    main()
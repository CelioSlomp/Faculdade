def main():
    lista = []
    while True:
        num = input("Digite um numero")
        if num == "":
            break
        lista.append(int(num))
    media = 0
    for i in lista:
        media += i
    media = media/len(lista)
    lista2 = []

    for i in lista:
        if i < media:
            lista2.append(i)
    for i in lista:
        if i == media:
            lista2.append(i)
    for i in lista:
        if i > media:
            lista2.append(i)
    return lista2

if __name__ == "__main__":
    print(main())

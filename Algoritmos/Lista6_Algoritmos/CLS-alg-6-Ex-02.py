def main():
    lista = []
    while True:
        numero = int(input("Digite um numero: "))
        if numero == 0:
            break
        lista.append(numero)

    lista.sort(reverse=True)
    lista2 = []
    for i in lista:
        lista2.append(i)
    return lista2

if __name__ == "__main__":
    for i in main():
        print(i)


def main():
    lista = []

    while True:
        palavra = input("Digite uma palavra")
        if palavra == "0":
            break
        lista.append(palavra)

    lista.sort()
    lista2 = []
    for i in lista:
        lista2.append(i)
    return lista2
if __name__ == "__main__":
    for i in main():
        print(i)

def main():
    lista = []
    lista2 = []
    while True:
        x = input("Digite um numero: ")
        if x == "":
            for i in lista:
                if i < 0:
                    lista2.append(i)
            for i in lista:
                if i == 0:
                    lista2.append(i)
            for i in lista:
                if i > 0:
                    lista2.append(i)
            return lista2
        else:
            lista.append(int(x))

if __name__ == "__main__":
    for i in main():
        print(i)

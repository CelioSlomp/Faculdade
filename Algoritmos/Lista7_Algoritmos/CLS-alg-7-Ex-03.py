def main():
    valor = input("Digite um valor a ser buscado: ").split(" ")
    dictio = {"a": 1, "b": 2, "c":3, "d":4, "e":5, "f":6}
    return buscaReversa(dictio, valor)

def buscaReversa(dicio, val):
    lista = []
    for i in val:
        if i in dicio:
            lista.append(dicio[i])
    return lista

if __name__ == "__main__":
    print(main())
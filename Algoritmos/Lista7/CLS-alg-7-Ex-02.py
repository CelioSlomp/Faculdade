def main():
    m = input("Digite um conjunto de numeros: ").split(" ")
    for i in range(0, len(m)):
        m[i] = int(m[i])
    m.sort()
    n = input("Digite um conjunto de numeros: ").split(" ")
    for i in range(0, len(n)):
        n[i] = int(n[i])
    n.sort()
    lista = list(caractUnicos(m, n))
    lista.sort()
    return(lista)

def caractUnicos(m, n):
    m = set(m)
    n = set(n)
    return m.difference(n).union(n.difference(m))

if __name__ == "__main__":
    print(main())
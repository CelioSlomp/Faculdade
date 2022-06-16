from random import randint

def main():
    min = 75
    max = 0
    medio = 0
    lista = []
    cart = cartela()
    for rodada in range(0, 1000):
        while True:
            num = randint(1, 75)
            if num in lista:
                pass
            else:
                lista.append(num)
                if verColuna(cart, lista) or verLinha(cart, lista) or verDiagonais(cart, lista):
                    if len(lista) < min:
                        min = len(lista)
                    if len(lista) > max:
                        max = len(lista)
                    medio += len(lista)   
                    break
    medio /= 1000
    return f"Minimo: {min}\nMedio: {medio}\nMaximo: {max}"

def verColuna(dici: dict, numeros: list):
    for i in dici:
        soma = 0
        for j in range(0, len(dici[i])):
            if dici[i][j] in numeros:
                dici[i][j] = 0
            else:
                soma += dici[i][j]
        if soma == 0:
            return True
    return False

def verLinha(dici:dict, numeros: list):
    for i in range(0, 5):
        soma = 0
        for j in dici:
            if dici[j][i] in numeros:
                dici[j][i] = 0
            else:
                soma += dici[j][i]
        if soma == 0:
            return True
    return False

def verDiagonais(dici:dict, numeros: list):
    soma = 0
    cont = 0
    for i in dici:
        if dici[i][cont] in numeros:
            dici[i][cont] = 0
        else:
            soma += dici[i][cont]
        cont += 1
    if soma == 0:
        return True

    soma = 0
    cont = 4
    for i in dici:
        if dici[i][cont] in numeros:
            dici[i][cont] = 0
        else:
            soma += dici[i][cont]
        cont -= 1
    if soma == 0:
        return True
    
    return False  

def cartela():
    listaGeral = [[], [], [], [], []]
    prim = 1
    ulti = 15
    for i in range(0,5):
        while len(listaGeral[i]) != 5:
            val = randint(prim, ulti)
            if val in listaGeral[i]:
                pass
            else:
                listaGeral[i].append(val)

        prim += 15
        ulti += 15

    for i in range(0, len(listaGeral)):
        listaGeral[i].sort()
    dicio = {"B": listaGeral[0], "I":listaGeral[1], "N":listaGeral[2], "G":listaGeral[3], "O": listaGeral[4]}
    return dicio
    
if __name__ == "__main__":
    print(main())
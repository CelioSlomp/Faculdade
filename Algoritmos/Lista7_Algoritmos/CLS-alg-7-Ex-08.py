from random import randint

def main():
    lista = []
    cart = cartela()
    while True:
        num = randint(1, 75)
        if num in lista:
            pass
        else:
            lista.append(num)
            if verColuna(cart, lista) or verLinha(cart, lista) or verDiagonais(cart, lista):
                return "Bingo"

def verColuna(dici: dict, numeros: list):
    for i in dici:
        soma = 0
        for j in range(0, len(dici[i])):
            if dici[i][j] in numeros:
                dici[i][j] = 0
            else:
                soma += dici[i][j]
        if soma == 0:
            cart = "| B | I | N | G | O |"
            for i in range(0, 5):
                cart += f"\n| {dici['B'][i]} | {dici['I'][i]} | {dici['N'][i]} | {dici['G'][i]} | {dici['O'][i]}"
            print("Sua cartela:\n", cart)
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
            cart = "| B | I | N | G | O |"
            for i in range(0, 5):
                cart += f"\n| {dici['B'][i]} | {dici['I'][i]} | {dici['N'][i]} | {dici['G'][i]} | {dici['O'][i]}"
            print("Sua cartela:\n", cart)
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
        cart = "| B | I | N | G | O |"
        for i in range(0, 5):
            cart += f"\n| {dici['B'][i]} | {dici['I'][i]} | {dici['N'][i]} | {dici['G'][i]} | {dici['O'][i]}"
        print("Sua cartela:\n", cart)
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
        cart = "| B | I | N | G | O |"
        for i in range(0, 5):
            cart += f"\n| {dici['B'][i]} | {dici['I'][i]} | {dici['N'][i]} | {dici['G'][i]} | {dici['O'][i]}"
        print("Sua cartela:\n", cart)
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

    cart = "| B | I | N | G | O |"
    for i in range(0, 5):
        cart += f"\n| {dicio['B'][i]} | {dicio['I'][i]} | {dicio['N'][i]} | {dicio['G'][i]} | {dicio['O'][i]}"
    print("Sua cartela:\n", cart)
    return dicio
    
if __name__ == "__main__":
    print(main())
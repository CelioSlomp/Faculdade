from random import randint

def main():
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
    return cart
    

if __name__ == "__main__":
    print(main())
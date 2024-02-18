def main():
    pala1 = input("Digite a frase 1: ").lower()
    pala2 = input("Digite a frase 2: ").lower()
    return anagrama(pala1, pala2)

def anagrama(pal1:str, pal2:str):
    pala1 = ""
    pala2 = ""
    for i in pal1:
        if i != " ":
            pala1 +=i
    for i in pal2:
        if i != " ":
            pala2 +=i

    dicio1 = {}
    dicio2 = {}
    for i in pala1:
        if dicio1.get(i) == None:
            dicio1[i] = 1
        else:
            dicio1[i] += 1
    for i in pala2:
        if dicio2.get(i) == None:
            dicio2[i] = 1
        else:
            dicio2[i] += 1
    if dicio1 == dicio2:
        return True
    return False


if __name__ == "__main__":
    print(main())
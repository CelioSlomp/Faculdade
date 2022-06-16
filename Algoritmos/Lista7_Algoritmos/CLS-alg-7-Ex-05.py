def main():
    pala1 = input("Digite a palavra 1: ")
    pala2 = input("Digite a palavra 2: ")
    return anagrama(pala1.lower(), pala2.lower())

def anagrama(pal1:str, pal2:str):
    dicio1 = {}
    dicio2 = {}
    for i in pal1:
        if dicio1.get(i) == None:
            dicio1[i] = 1
        else:
            dicio1[i] += 1
    for i in pal2:
        if dicio2.get(i) == None:
            dicio2[i] = 1
        else:
            dicio2[i] += 1
    
    if dicio1 == dicio2:
        return True
    return False


if __name__ == "__main__":
    print(main())
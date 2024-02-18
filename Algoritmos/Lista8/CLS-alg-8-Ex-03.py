def main():
    palavra = input("Digite uma palavra ou frase: ")
    pala = ""
    for i in palavra:
        if i in "abcdefghijklmnopqrstuvwxyz":
            pala += i
    return palindromo(pala)

def palindromo(pal:str):
    if len(pal) <= 1:
        return True
    elif pal[0] != pal[-1]:
        return False
    else:
        return palindromo(pal[1:-1])

if __name__ == "__main__":
    print(main())
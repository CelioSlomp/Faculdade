def main():
    frase = input("Digite uma frase: ")
    return seppal(frase)
def seppal(frase):
    frase = frase.split(" ")
    frasefin = ""
    rod = 0
    for i in frase:
        rod += 1
        if rod == len(frase)-1:
            frasefin += i +" e "
        elif rod == len(frase):
            frasefin += i
        else:
            frasefin += i + ", "
    #frasefin = frasefin[2:]
    return frasefin


if __name__ == "__main__":
    print(main())
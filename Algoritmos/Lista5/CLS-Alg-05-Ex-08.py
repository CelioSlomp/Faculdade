def main():
    frase = input("Digite uma frase: ")
    return correct(frase)

def correct(frase):
    afrase = frase[0].upper()
    podepular = 0
    for i in range(0, len(frase)):
        if i == podepular or i == podepular-1:
            pass
        else:
            if frase[i] == "." or frase[i] == "!" or frase[i] == "?":
                if i < len(frase)-2:
                    afrase += frase[i] + " "
                    afrase += frase[i+2].upper()
                    podepular = i+2
            else:
                afrase += frase[i]
    afrase += frase[-1]
    return afrase

if __name__ == "__main__":
    print(main())
def main():
    numero = input("Digite a string: ")
    print("O valor é inteiro? " + str(eInteiro(numero)))

def eInteiro(palavra):
    opal = ""

    palavra = str(palavra).replace(" ", "")
    if palavra[0] == "-":
        for i in range(0, len(palavra)):
            if i == 0 and palavra[i] == "-":
                pass
            else:
                opal += palavra[i]
    for i in opal:
        if i == "0" or i == "1" or i == "2" or \
        i == "3" or i == "4" or i == "5" or \
        i == "6" or i == "7" or i == "8" or \
        i == "9":
            pass
        else:
            return False
    return True    
if __name__ == "__main__":
    main()
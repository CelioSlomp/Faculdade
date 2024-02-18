def main():
    numero = int(input("Digite o numero: "))
    return ordinais(numero)

def ordinais(num):
    if num == 1:
        return "primeiro"
    elif num == 2:
        return "segundo"
    elif num == 3:
        return "terceiro"
    elif num == 4:
        return "quarto"
    elif num == 5:
        return "quinto"
    elif num == 6:
        return "sexto"
    elif num == 7:
        return "setimo"
    elif num == 8:
        return "oitavo"
    elif num == 9:
        return "nono"
    elif num == 10:
        return "decimo"
    elif num == 11:
        return "decimo primeiro"
    elif num == 12:
        return "decimo segundo"
    else:
        return ""    


if __name__ == "__main__":
    print(main())
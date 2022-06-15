def main():
    numes = int(input("Digite o numero do mes: "))
    nuano = int(input("Digite o numero do ano: "))
    valor = dias(numes, nuano)
    if valor != None:
        return "Esse mes possui %i dias" %valor
    else:
        return "Esse mes não existe."
    
def dias(numes, nuano):
    if numes == 12 or numes == 10 or \
        numes == 1 or numes == 3 or \
        numes == 5 or numes == 7 or \
        numes == 8:
        return 31
    elif numes == 4 or numes == 6 or\
        numes == 9 or numes == 1:
        return 30
    elif numes == 2:
        if (nuano%400 == 0) or (nuano%4 == 0):
            return 29
        else:
            return 28    
    else:
        return None




if __name__ == "__main__":
    print(main())
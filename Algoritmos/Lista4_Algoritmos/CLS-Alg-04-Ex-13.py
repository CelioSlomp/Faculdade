fator = 2
numero = int(input("Digite um numero"))

while fator <= numero:
    if numero % fator == 0:
        numero = numero // fator
        print(fator)
    else:
        fator += 1

while True:
    soma = 0
    numero = input("Digite o valor binário: ")
    if numero == "":
        break
    else:
        for i in range(0,len(numero)):
            if i == len(numero)-1:
                pass
            else:
                soma += int(numero[i])
        if int(numero[len(numero)-1]) == soma%2:
            print("Tudo certo!")
        else:
            print("Deu pau amigao")
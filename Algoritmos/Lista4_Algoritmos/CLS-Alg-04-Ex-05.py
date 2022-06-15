preco = 0
while True:
    idade = input("Digite a idade: ")
    if idade == "":
        break
    else:
        idade = int(idade)
        if idade < 3:
            preco += 0
        elif idade >=3 and idade <= 12:
            preco += 14
        elif idade >= 65:
            preco += 18
        else:
            preco += 23
print("O preco total foi de R$%.2f" % preco)
menor = float(input("Digite aquantidade de vasilhames menores ou iguais a um litro: "))
maior = float(input("Digite aquantidade de vasilhames maiores que um litro: "))
print("O crédito é de R$%.2f" % (menor*0.10 + maior*0.25) )
valor = 4.95
x = 0
while x < 5:
    print("--------------------------------")
    print("Valor dos produtos de R$%.2f" % valor)

    print("Desconto de: R$%.2f" % (valor*0.40))

    print("Preço Final: R$%.2f" % (valor*0.60))
    valor += 5
    x += 1
print("--------------------------------")
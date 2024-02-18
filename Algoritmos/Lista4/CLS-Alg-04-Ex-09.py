x = float(input("Digite o valor: "))
raiz = x/2

while x - raiz * raiz > 0.1**12:
    raiz = (raiz + x/raiz)/2
print(raiz)
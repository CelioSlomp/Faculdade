numero = int(input("Digite um numero: "))

result = ""
while numero != 0:
    result = str(numero % 2) + result
    numero = numero//2
print(result)

b = input("digite o numero binario: ")
soma = 0
val = 0
for i in range(len(b)-1, -1, -1):
    soma += int(b[i])* (2**val)
    val += 1
print(soma)

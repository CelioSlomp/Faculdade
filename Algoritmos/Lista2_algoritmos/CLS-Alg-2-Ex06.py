numero = int(input("Digite o numero: "))

soma = 0
soma += numero//1000
numero -= 1000*(numero//1000)

soma += numero//100
numero -= 100*(numero//100)

soma += numero//10
numero -= 10*(numero//10)

soma += numero

print(soma)
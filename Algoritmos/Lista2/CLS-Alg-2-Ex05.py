valor = int(input("Digite os centavos: "))

cinquenta = valor//50
valor -= 50*cinquenta

vintecinco = valor//25
valor -= 25*vintecinco

dez = valor//10
valor -= 10*dez

cinco = valor//5
valor -= 5*cinco

print("Moedas de cinquenta:", cinquenta)
print("Moedas de vinte e cinco:", vintecinco)
print("Moedas de dez:", dez)
print("Moedas de cinco:", cinco)
print("Moedas de um:", valor)
data = int(input("Digite a data: "))

ano = data//10000
data -= ano*10000

mes = data //100
data -= mes*100

dia = data

print(dia*10000 + mes*100 + ano)
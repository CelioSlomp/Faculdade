dias = int(input("Digite a quantidade de dias: "))
horas = int(input("Digite a quantidade de horas: ")) + (dias * 24)
minutos = int(input("Digite a quantidade de minutos: ")) + (horas * 60)
segundos = int(input("Digite a quantidade de segundos: ")) + (minutos * 60)
print("O tempo tem %a segundos" % segundos)
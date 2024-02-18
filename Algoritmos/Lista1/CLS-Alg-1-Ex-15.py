from math import pi, tan

lado = float(input("Digite o lado: "))
numeroLados = int(input("Digite o numero de lados: "))

print("Area:", (numeroLados*lado**2) / (4 * tan(pi/numeroLados)) )
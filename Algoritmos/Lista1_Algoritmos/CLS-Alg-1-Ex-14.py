lado1 = float(input("Digite o lado 1: "))
lado2 = float(input("Digite o lado 2: "))
lado3 = float(input("Digite o lado 3: "))
l = (lado1 + lado2 + lado3)/2
print("Area:", (l * (l-lado1) * (l-lado2) * (l-lado3) )**0.5)
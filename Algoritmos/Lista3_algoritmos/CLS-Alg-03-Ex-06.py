a = int(input("Digite o lado A: "))
b = int(input("Digite o lado B: "))
c = int(input("Digite o lado C: "))

if a == b == c:
    print("Triangulo Equilatero")
elif (a!=b) and (a!=c) and (b!=c):
    print("Triangulo Escaleno")
else:
    print("Triangulo Isosceles")
a = int(input("Digite o valor de A: "))
b = int(input("Digite o valor de B: "))
c = int(input("Digite o valor de C: "))

if (b**2 -4*a*c) < 0:
    print("Discriminante negativo.")
elif (b**2 -4*a*c) == 0:
    print(-b/2*a)
else:
    print((-b + (b**2 +((-4)*a*c))**0.5)/(2*a))
    print((-b - (b**2 +((-4)*a*c))**0.5)/(2*a))
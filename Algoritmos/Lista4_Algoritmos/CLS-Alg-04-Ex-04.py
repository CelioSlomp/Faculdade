soma = 0
x1 = input("Digite o x: ")
if x1 == "":
    pass
else:
    x1 = float(x1)
    y1 = float(input("Digite o y: "))
    while True:
        x2 = input("Digite o x: ")
        if x2 == "":
            break
        else:
            x2 = float(x2)
            y2 = float(input("digite o y: "))
            soma += (abs(y2 - y1)**2 + abs(x2 - x1)**2)**0.5
            x1 = x2
            y1 = y2
    
print(soma+1)
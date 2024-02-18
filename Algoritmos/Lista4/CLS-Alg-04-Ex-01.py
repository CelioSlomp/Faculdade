x = 0
media = 0
while True:
    nota = int(input("Digite a nota do aluno: "))
    if nota == 0:
        break
    else:
        x+=1
        media+= nota

print("A media é: %.2f" % (media/x))
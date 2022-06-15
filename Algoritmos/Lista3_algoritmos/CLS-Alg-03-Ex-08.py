nota = input("Digite a nota: ")
digito = nota[0].lower()
numero = int(nota[1])

if digito == "c":
    print(261.63/2**(4-numero))
elif digito == "d":
    print(293.66/2**(4-numero))
elif digito == "e":
    print(329.63/2**(4-numero))
elif digito == "f":
    print(349.23/2**(4-numero))
elif digito == "g":
    print(392.00/2**(4-numero))
elif digito == "a":
    print(440.00/2**(4-numero))
elif digito == "b":
    print(493.88/2**(4-numero))
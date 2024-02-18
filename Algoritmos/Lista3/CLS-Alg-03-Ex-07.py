valor = int(input("Digite o volume sonoro: "))

if valor == 130:
    print("valor é igual ao de uma britadeira.")
elif valor == 106:
    print("valor é igual ao de um cortador de grama.")
elif valor == 70:
    print("valor éigual ao de um despertador.")
elif valor == 40:
    print("valor é igual ao de uma sala sienciosa.")
elif valor > 130:
    print("valor muito alto.")
elif valor < 40:
    print("valor muito baixo.")
elif valor < 130 and valor > 106:
    print("valor é menor que  uma britadeira so que  maior que umcortador de grama.")
elif valor < 106 and valor > 70:
    print("valor e maior que um despertador so que menor que um cortado de  grama.")
elif valor < 70 and valor > 40:
    print("valor é maior que a sala silenciosa so que menor que um despertador.")
    
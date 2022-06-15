idade = int(input("Digite a idade do cachorro: "))

if(idade < 0):
    print("Idade negativa amigao?")
else:
    if idade <= 2:
        print(idade*10.5, "anos")
    else:
        idadecanina = 2*10.5 + (idade-2)*4
        print(idadecanina, "anos")
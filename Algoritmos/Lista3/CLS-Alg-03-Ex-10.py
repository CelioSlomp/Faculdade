casa = input("Digite a casa do xadrez: ")

if casa[0] == "a" or casa[0] == "e" or \
    casa[0] == "c" or casa[0] == "g":
    if int(casa[1])%2 == 1:
       print("casa preta")
    else:
        print("casa branca")
else:
    if int(casa[1])%2 == 0:
       print("casa preta")
    else:
        print("casa branca")
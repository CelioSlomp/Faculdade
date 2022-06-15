def main():
    print("Qual base que vai receber?")
    print("1 - binario")
    print("2 - decimal")
    print("3 - hexadecimal")

    tipo = int(input("Digite a base: "))
    if tipo == 1:
        bin = input("Digite o valor em binario: ")
        return bin2int(bin)
    elif tipo == 2:
        num = int(input("Digite o numero: "))
        print("Deseja converter para qual base? ")
        print("1 - Binario")
        print("2 - Hexadecimal")
        tipo =  int(input("Digite a opcao: "))
        if tipo == 1:
            return int2bin(num)
        elif tipo == 2:
            return int2hex(num)
    elif tipo == 3:
        hex = input("Digite o valor emhexadecimal: ")
        return hex2int(hex)
    else:
        print("tipo invalido.")

def hex2int(hex):
    soma =  0
    tam = len(hex)
    for i in hex:
        tam -= 1
        soma += hex2(i) * 16**tam
    print(soma)

def bin2int(bin):
    soma =  0
    tam = len(bin)
    for i in bin:
        tam -= 1
        soma += int(i) * 2**tam
    print(soma)

def hex2(hexa):
    hexa = str(hexa).upper()
    if hexa == "A":
        return 10
    elif hexa == "B":
        return 11
    elif hexa == "C":
        return 12
    elif hexa == "D":
        return 13
    elif hexa == "E":
        return 14
    elif hexa == "F":
        return 15
    else:
        return int(hexa)

def int2bin(num):
    binario = ""
    while True:
        binario = str(num%2) + binario
        num = int(num/2)
        if num == 1:
            binario = str(1) + binario
            break
    print(binario)

def int2hex(num):
    hexadecimal = ""
    while True:
        hexadecimal = numero_hex(num%16) + hexadecimal
        num = int(num/16)
        if num < 16:
            hexadecimal = numero_hex(num) + hexadecimal
            break
    print(hexadecimal)

def numero_hex(num):
    if num == 10:
        return "A"
    elif num == 11:
        return "B"
    elif num == 12:
        return "C"
    elif num == 13:
        return "D"
    elif num == 14:
        return "E"
    elif num == 15:
        return "F"
    else:
        return str(num)



if __name__ == "__main__":
    main()
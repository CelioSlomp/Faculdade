def main():
    num = int(input("Digite um numero para  converter para  hexadecimal: "))
    hex = input("Digite um numero hexadecimal: ")
    return f"O numero headecimal é {hex2int(hex)} e o inteiro é {int2hex(num)}"

def hex2int(hex):
    hex = str(hex).upper()
    if hex == "A":
        return 10
    elif hex == "B":
        return 11
    elif hex == "C":
        return 12
    elif hex == "D":
        return 13
    elif hex == "E":
        return 14
    elif hex == "F":
        return 15
    else:
        return int(hex)

def int2hex(num):
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
    print(main())
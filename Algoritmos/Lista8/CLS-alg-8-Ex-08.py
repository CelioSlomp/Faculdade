def main():
    num = int(input("Digite um numero (nao negativo) para converter: "))
    if num < 0:
        return "Numero Negativo"
    else:
        return decBinConv(num)

def decBinConv(n):
    if n == 0 or n == 1:
        return n
    else:
        val = n%2
        n = n//2
        return str(decBinConv(n)) + str(val)

if __name__ == "__main__":
    print(main())
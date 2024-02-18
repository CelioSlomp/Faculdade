def main():
    num = int(input("Digite um numero para a conversão: "))
    return decBinConv(num)

def decBinConv(q):
    result = ""
    while q != 0:
        r = q%2
        result = str(r) + result
        q = q//2
    return result

if __name__ == "__main__":
    print(main())
def main():
    a = int(input("Digite um valor: "))
    b = int(input("Digite um outro valor: "))
    return mdc(a, b)

def mdc(a,b):
    if b == 0:
        return a
    else:
        c = a%b
        return mdc(b, c)


if __name__ == "__main__":
    print(main())
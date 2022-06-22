def main():
    num = input("Digite um numero: ")
    if num.endswith("!"):
        try:
            temp = int(num.removesuffix("!"))
            return fatorial(int(temp))

        except ValueError:
            return "Não está com numero certo"
    else:
        return fatorial(int(num))

def fatorial(n):
    if n == 1:
        return 1
    else:
        return n * fatorial(n-1)

if __name__ == "__main__":
    print(main())
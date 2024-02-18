def main():
    num = int(input("Digite um numero: "))
    numdiv = []
    for i in range(1, num):
        if num % i == 0:
            numdiv.append(i)
    soma = 0
    for i in numdiv:
        soma += i
    if soma == num:
        return True
    else:
        return False

if __name__ == "__main__":
    print(main())

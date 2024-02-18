def main():
    valor1 = int(input("Digite o valor 1: "))
    valor2 = int(input("Digite o valor 2: "))
    valor3 = int(input("Digite o valor 3: "))
    return "O valor da mediana é: %a" % mediana(valor1, valor2, valor3)

def mediana(v1, v2, v3):
    mediana = (v1 + v2 + v3) - min(v1, v2, v3) - max(v1, v2, v3)
    return mediana

if __name__ == "__main__":
    print(main())
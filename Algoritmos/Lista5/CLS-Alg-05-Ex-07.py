def main():
    lado1 = int(input("Digite o valor do lado 1: "))
    lado2 = int(input("Digite o valor do lado 2: "))
    lado3 = int(input("Digite o valor do lado 3: "))
    if validade(lado1, lado2, lado3):
        return "triangulo valido."
    else:
        return "triangulo invalido."

def validade(l1, l2, l3):
    meio = mediana(l1, l2, l3)
    maior = max(l1, l2, l3)
    menor = min(l1, l2, l3)

    if maior >= menor + meio:
        return False
    else:
        return True

def mediana(v1, v2, v3):
    mediana = (v1 + v2 + v3) - min(v1, v2, v3) - max(v1, v2, v3)
    return mediana

if __name__ == "__main__":
    print(main())
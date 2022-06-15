def main():
    lado1 = float(input("Digite o lado 1: "))
    lado2 = float(input("Digite o lado 2: "))
    return(hipotenusa(lado1, lado2))

def hipotenusa(l1, l2):
    hip = (l1**2 + l2**2)**0.5
    return hip

if __name__ == "__main__":
    print("A hipoteenusa é: %.2f" % main())
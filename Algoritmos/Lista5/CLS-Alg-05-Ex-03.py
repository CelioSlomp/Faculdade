def main():
    itens = int(input("Digite a quantidade de itens: "))
    return frete(itens)

def frete(ite):
    if ite <= 0:
        return "Itens insuficientes."
    elif ite == 1:
        return "O preço final foi de R$%.2f" % 10.95
    else:
        return "O preço final foi de R$%.2f" % (10.95 + (ite-1)*2.95)

if __name__ == "__main__":
    print(main())
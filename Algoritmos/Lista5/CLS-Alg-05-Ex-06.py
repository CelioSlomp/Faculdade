def main():
    texto = input("Digite uma string: ")
    taman = int(input("digite o tamanho da string"))
    if taman > len(texto):
        return centralizarr(texto, taman)
    else:
        return "tamanho menor do que o da string."

def centralizarr(texto, taman):
    strin = ""
    for i in range(0, taman-len(texto)):
        strin += " "
    strin += texto
    return strin

if __name__ == "__main__":
    print(main())
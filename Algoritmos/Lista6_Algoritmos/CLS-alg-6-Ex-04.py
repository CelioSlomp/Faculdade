def main():
    palavras = []
    while True:
        palavra = input("Digite uma palavra: ")
        if palavra == "":
            return palavras
        if palavra in palavras:
            pass
        else:
            palavras.append(palavra)

if __name__ == "__main__":
    for i in main():
        print(i)

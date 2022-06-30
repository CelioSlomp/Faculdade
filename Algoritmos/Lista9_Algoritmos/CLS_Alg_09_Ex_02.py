def main():
    f = open("Palavras_portugues_br-utf8.txt", "r")
    cont = 0
    for i in f:
        print(i)
        cont += 1
        if cont == 10:
            break

if __name__ == "__main__":
    main()
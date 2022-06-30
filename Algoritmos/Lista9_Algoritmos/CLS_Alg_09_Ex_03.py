def main():
    f = open("Palavras_portugues_br-utf8.txt", "r")
    x = f.readlines()
    x.reverse()
    for i in x[10: 0: -1]:
        print(i)


if __name__ == "__main__":
    main()
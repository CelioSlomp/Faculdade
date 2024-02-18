def main():
    palavra = input("Digite uma palavra:")
    palavra2 = ""
    for i in palavra:
        if i == "!" or i == "?" or i == "," or i == ".":
            pass
        else:
            palavra2 += i
    palavra2 = palavra2.split(" ")
    return palavra2

if __name__ == "__main__":
    print(main())

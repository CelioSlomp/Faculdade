def main():
    num = input("Digite um numero: ")
    try:
        num = int(num)
        return num + main()
    except ValueError:
        return 0

if __name__ == "__main__":
    print(main())
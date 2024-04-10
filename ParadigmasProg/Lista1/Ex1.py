def detonarBomba(num):
    if not num:
        print("BOOM!")
        return 0
    print(num)
    return detonarBomba(num-1)

if __name__ == "__main__":
    detonarBomba(int(input("Digite o timer: ")))
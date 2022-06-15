def main():
    num = int(input("Digite um numero:"))
    numdiv = []
    for i in range(1, num+1):
        if num % i == 0:
            numdiv.append(i)
    return numdiv

if __name__ == "__main__":
    for i in main():
        print(i)

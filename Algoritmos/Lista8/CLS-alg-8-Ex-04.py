def main():
    num = int(input("digite um numero: "))
    return fibonacci(num)
    
dici = {0:0, 1:1}
def fibonacci(num):
    if num in dici:
        return dici[num]
    n = fibonacci(num-1) + fibonacci(num-2)
    dici[num] = n
    return n


if __name__ == "__main__":
    print(main())
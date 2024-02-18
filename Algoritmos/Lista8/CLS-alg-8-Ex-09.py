def main():
    num = int(input("Digite um numero: "))
    est = input("Digite a estimativa: ")
    if est == "":
        return raizQuad(num)
    else:
        est = int(est)
        return raizQuad(num, est)

def raizQuad(num, est=1):
    x = (est**2)-num
    if x > 0:
        if x < 0.1**(12):
            return est
        else:
            est = (est + (num/est))/2
            return raizQuad(num, est)
    else:
        x = x * -1
        if x < 0.1**(12):
            return est
        else:
            est = (est + (num/est))/2
            return raizQuad(num, est)

if __name__ == "__main__":
    print(main())
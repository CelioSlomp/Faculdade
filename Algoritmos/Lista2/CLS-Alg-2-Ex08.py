N = int(input("Digite o numero N: "))

C = N//100
N -= 100*(N//100)

D = N//10
N -= 10*(N//10)

U = N

print("M =", U*100 + D*10 + C)
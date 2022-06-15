N = int(input("Digite o numero N: "))

C = N//100
N -= 100*(N//100)

D = N//10
N -= 10*(N//10)

print("C =", C, "D =", D, "e U =", N)
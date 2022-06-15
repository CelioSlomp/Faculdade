matricula = int(input("Digite o codigo de matricula: "))

ano  = matricula//10000
matricula -= ano*10000

print("ano:", ano, "semetre:", matricula//1000)
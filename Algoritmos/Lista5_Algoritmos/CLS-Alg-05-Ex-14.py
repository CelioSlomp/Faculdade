def main():
    dia = int(input("Digite o dia: "))
    mes = int(input("Digite o mes: "))
    ano = int(input("Digite o ano: "))
    if verdata(dia, mes, ano):
        return "É uma data  magica."
    else:
        return "Não é uma data magica."

def verdata(dia, mes, ano):
    diames = dia * mes
    ano = ano - ((ano//1000)*1000)
    ano = ano - ((ano//100)*100)
    if diames == ano:
        return True
    else:
        return False

if __name__ == "__main__":
    print(main())
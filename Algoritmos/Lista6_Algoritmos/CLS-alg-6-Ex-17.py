def main():
    formula = input("Digite uma formula: ")
    return aval(formula)

def aval(formula):
    formula = formula.split(" ")
    valores = []
    for i in formula:
        try:
            if int(i)/1 == int(i):
                valores.append(i)
            
        except ValueError:
            direita = valores[-1]
            valores[-1] = ""
            esquerda = valores[-1]
            valores[-1] = ""
            valores.append(esquerda + " " + i + " " + direita)
    
    for i in valores:
        if i == "":
            valores.remove("")
    return valores




if __name__ == "__main__":
    print(main())
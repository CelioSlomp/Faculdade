def token(formula):
    formula = formula.replace(" ", "")
    numero = ''
    token = []
    for indice,i in enumerate(formula):

        if i in ['/','*','^','(',')','=']:
            if numero != '':
                token.append(int(numero))
            numero = ''
            token.append(i)

        elif i in ['-','+']:
            if formula[indice-1] in '0987654321)' and indice != 0:
                if numero != '':
                    token.append(int(numero))
                numero = ''
                token.append(i)
            else:
                numero += i

        elif i in '0987654321':
            numero += i
            if indice + 1 == len(formula):
                if numero != '':
                    token.append(int(numero))

    return token

def enumero(texto):
    texto = texto.strip()

    for i in range(0, len(texto)):
        if (i == 0) and len(texto) > 1:
            if (texto[i] == "+" or texto[i] == "-"):
                continue
        try:
            int(texto[i])
        except ValueError:
            return False
  
    return True

def precedencia(operador):
    if (operador == "+" or operador == "-"):
        return 1
    elif (operador == "*" or operador == "/"):
        return 2
    elif (operador == "^"):
        return 3
    else:
        return -1

def postfix(tokens):
    operadores = []
    postFix = []

    for token in tokens:

        token = str(token)

        if enumero(token):
            postFix.append(token)
        
        if token in "+-*/^":
            while (len(operadores) != 0) and (operadores[-1] != "(") and (precedencia(token) <= precedencia(operadores[-1])):
                postFix.append(operadores.pop())
            operadores.append(token)
        
        if token == "(":
            operadores.append(token)
        
        if token == ")":
            while operadores[-1] != "(":
                postFix.append(operadores.pop())
            operadores.remove("(")
    
    while len(operadores) != 0:
        postFix.append(operadores.pop())
    
    return postFix

def main():
    formula = input("Digite uma formula: ")
    tokens = token(formula)
    postfi = postfix(tokens)
    saida = ""
    for elemento in tokens:
        saida = saida + str(elemento) + " "
    print("normal: " + saida)
    saida = ""
    for i in postfi:
        saida = saida + str(i) + " "
    print("posfixa: " + saida)        

if __name__ == "__main__":
    main()

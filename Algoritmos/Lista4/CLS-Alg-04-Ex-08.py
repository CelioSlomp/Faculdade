while True:
    print("1 - Codificar")
    print("2 - Descodificar")
    print("3 - Parar")
    operacao = int(input("O que desejas fazer?"))
    if operacao == 1:
        codificadda = ""
        palavra = input("Digite a palavra para codificar: ")
        for i in palavra:
            if ord(i) == 88:
                codificadda += chr(88 - 23)
            elif ord(i) == 89:
                codificadda += chr(89 - 23)
            elif ord(i) == 90:
                codificadda += chr(90 - 23)
            elif ord(i) <=87 and ord(i) >= 65:
                codificadda += chr(ord(i)+3)
            elif ord(i) == 120:
                codificadda += chr(120 - 23)
            elif ord(i) == 121:
                codificadda += chr(121 - 23)
            elif ord(i) == 122:
                codificadda += chr(122 - 23)
            elif ord(i) <=119 and ord(i) >= 97:
                codificadda += chr(ord(i)+3)
            else:
                codificadda += " "
        print("A palavra após a codificacaoé: ",codificadda)
    elif operacao == 2:
        palavra = input("Digite a palavra codificada: ")
        descodificada = ""
        for i in palavra:
            if ord(i) == 65:
                descodificada += chr(65 + 23)
            elif ord(i) == 66:
                descodificada += chr(66 + 23)
            elif ord(i) == 67:
                descodificada += chr(67 + 23)
            elif ord(i) <=87 and ord(i) >= 65:
                descodificada += chr(ord(i)-3)
            elif ord(i) == 95:
                descodificada += chr(95 + 23)
            elif ord(i) == 96:
                descodificada += chr(96 + 23)
            elif ord(i) == 97:
                descodificada += chr(97 + 23)
            elif ord(i) <=119 and ord(i) >= 97:
                descodificada += chr(ord(i)-3)
            else:
                descodificada += " "
        print("A palavra descodificada é:", descodificada)

    elif operacao == 3:
        break
    else:
        pass
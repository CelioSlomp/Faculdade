def main():
    senha = input("Digite a senha: ")
    if verifsenha(senha):
        return "A senha é valida."
    else:
        return "A senha nao e valida."

def verifsenha(senha):
    numero = False
    letraMai = False
    senha = str(senha)
    for i in senha:        
        if i == "0" or i == "1" or i == "2" or \
        i == "3" or i == "4" or i == "5" or \
        i == "6" or i == "7" or i == "8" or \
        i == "9":
            numero = True
        if i.isupper():
        
            letraMai = True
    if  numero and letraMai and len(senha)>=8:
        return True
    else:
        return False

if __name__ == "__main__":
    print(main())
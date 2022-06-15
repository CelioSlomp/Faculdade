def main():
    lista = []
    
    while True:
        num = int(input("Digite um numero"))
        if num == 0:
            if len(lista) < 5:
                print("Deu pau amigao")
                return "Erro"
            else:
                break
        lista.append(num)
    ambas = []
    lista2 = tuple(lista)
    ambas.append(lista2)
    lista.remove(lista[0]) 
    lista.remove(lista[0])
    lista.remove(lista[-1])
    lista.remove(lista[-1])
    ambas.append(lista)
    return ambas
if __name__ == "__main__":
    var = main()
    if var == "Erro":
        pass
    else:
        print(var[0])
        print(var[1])

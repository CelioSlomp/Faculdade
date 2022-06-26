def main():
    listaDesc = []
    print("Digite os valores, caso acabe, nao insira nada e aperte enter.")
    while True:
        val1 = input("Digite um valor: ")
        if val1 == "":
            break
        val2 = int(input("Digite o numero: "))
        listaDesc.append(val1)
        listaDesc.append(val2)
    var = decrunlenght(listaDesc).split(" ")
    var.remove(var[0])
    return var

    
def decrunlenght(li: list):
    st = " "
    try:
        if li[1] == 0:
            li.remove(li[0])
            li.remove(li[0])
            st += li[0]
            li[1] = li[1] - 1
            return st + decrunlenght(li)
        else:
            st += li[0]
            li[1] = li[1] - 1
            return st + decrunlenght(li)
    except:
        return ""

if __name__ == "__main__":
    print(main())
def main():
    listaDesc = []
    print("Digite os valores, caso acabe, nao insira nada e aperte enter.")
    while True:
        val1 = input("Digite um valor: ")
        if val1 == "":
            break
        listaDesc.append(val1)
    var = codrunlenght(listaDesc).split(" ")
    var = var[:-1]
    for i in range(0, len(var)):
        try:
            var[i] = int(var[i])
        except:
            pass
    return var

def codrunlenght(li: list):
    st = ""
    cont = 0
    try:
        w1 = li[0]
        for i in range(0, len(li)):
            if li[0] != w1:
                break
            else:
                li.remove(li[0])
                cont += 1
    except:
        return ""
    st = w1 + " " + str(cont)
    return st + " " + codrunlenght(li)

if __name__ == "__main__":
    print(main())
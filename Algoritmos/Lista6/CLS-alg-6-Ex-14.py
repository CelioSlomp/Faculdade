def main():
    operador = input("Digite um operador: ")
    return precedencia(operador)

def precedencia(op):
    if op in ["+", "-"]:
        return 1
    elif op in ["*", "/"]:
        return 2
    elif op == "^":
        return 3
    else:
        return -1

if __name__ == "__main__":
    print(main())
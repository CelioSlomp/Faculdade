def main():
    distancia = float(input("Digite a distancia: "))
    return preco(distancia)

def preco(dist):
    precofixo = 4
    precoandado = (dist/0.14)*0.25
    return(precofixo + precoandado)

if __name__ == "__main__":
    print("A corrida deu:R$%.2f" % main())
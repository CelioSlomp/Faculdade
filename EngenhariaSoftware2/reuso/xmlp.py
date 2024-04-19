from bs4 import BeautifulSoup

def main():
    arq = open('tabela.xml', 'r')
    dados = arq.read()

    dados_lib = BeautifulSoup(dados, 'xml')

    tabelas = dados_lib.find_all('coluna')
    tabela = dados_lib.find('coluna')
    
    for i in tabelas:
        print(i)

if __name__ == "__main__":
    main()
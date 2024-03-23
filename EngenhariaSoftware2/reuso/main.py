import mysql.connector

def main():
    ## Cria a tabela e o cursor
    conn = mysql.connector.connect(host="127.0.0.1", user="celiols", password='1234', database="bancoDados")
    cursor = conn.cursor()

    nomeTabela = input("Digite o nome da tabela: ")

    cursor.execute("show columns from ".__add__(nomeTabela).__add__(";"))
    listaColunas = cursor.fetchall()

    for i in listaColunas:
        if i[3] == 'PRI':
            identificador = i[0]

def criarInsert():
    pass

def criarSelect():
    pass

def criarUpdate():
    pass

def criarDelete():
    pass

if __name__ == "__main__":
    main()
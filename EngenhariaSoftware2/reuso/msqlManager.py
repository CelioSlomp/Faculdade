import mysql.connector
import mariadb
from msql import criarDelete, criarInsert, criarSelect, criarUpdate, principal
from xmlp import criarTabela

def main():
    while True:
        print("----------------------------")
        print("1 - Criar tabela")
        print("2 - Criar procedures")

        x = int(input("O que desejas fazer?"))
        match x:
            case 1:
                x = int(input("Digite o banco (1 - MySQL; 2 - MariaDB): "))
                if x == 1:
                    createTableMysql()
                elif x == 2:
                    createTableMariadb()

            case 2:
                x = int(input("Digite o banco (1 - MySQL; 2 - MariaDB): "))
                if x == 1:
                    createProceduresMysql()
                elif x == 2:
                    createProceduresMariadb()


def createTableMysql():
    try:
        conn = mysql.connector.connect(host="127.0.0.1",       
                                       user="root",
                                       password='1234',
                                       database="bancoDados",
                                       port=3306)
        print("")
        cursor = conn.cursor()
    except mysql.connector.Error as erroMysql:
        print("Não foi possivel conectar no Mysql.")
        print(erroMysql)
    cursor.execute(criarTabela())

def createProceduresMysql():
    try:
        conn = mysql.connector.connect(host="127.0.0.1",       
                                       user="root",
                                       password='1234',
                                       database="bancoDados",
                                       port=3306)
        print("")
        cursor = conn.cursor()
    except mysql.connector.Error as erroMysql:
        print("Não foi possivel conectar no Mysql.")
        print(erroMysql)

    principal(cursor)

def createTableMariadb():
    try:
        conn = mariadb.connect(database="bancoDados",   # O banco de dados
                            host="localhost",       # Endereco do banco de dados
                            user="root",            # O usuario com premissoes (de preferencia root)
                            password="1234",        # A senha de usuario
                            port=3300)
        print("")
        cursor = conn.cursor()
    except mariadb.Error as erroMariaDB:
        print(erroMariaDB)

    cursor.execute(criarTabela())

def createProceduresMariadb():
    try:
        conn = mariadb.connect(database="bancoDados",   # O banco de dados
                            host="localhost",       # Endereco do banco de dados
                            user="root",            # O usuario com premissoes (de preferencia root)
                            password="1234",        # A senha de usuario
                            port=3300)
        print("")
        cursor = conn.cursor()
    except mariadb.Error as erroMariaDB:
        print(erroMariaDB)

    principal(cursor)




if __name__ == "__main__":
    main()
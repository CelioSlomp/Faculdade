import mysql.connector
import msql
from xmlp import criarTabela


def main():

    try:
        conn = mysql.connector.connect(host="127.0.0.1",       
                                       user="root",
                                       password='1234',
                                       database="bancoDados",
                                       port=3307)
        print("Conectado no Mysql")
    except mysql.connector.Error as erroMysql:
        print("Não foi possivel conectar no Mysql.")
        print(erroMysql)


    cursor = conn.cursor()

    cursor.execute(criarTabela())

if __name__ == "__main__":
    main()
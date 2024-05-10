import mysql.connector
import msql
from xmlp import criarTabela


def main():
    conn = mysql.connector.connect(host="127.0.0.1",       
                                   user="root",
                                   password='1234',
                                   database="bancoDados",
                                   port=3307)
    
    cursor = conn.cursor()

    cursor.execute(criarTabela())

if __name__ == "__main__":
    main()
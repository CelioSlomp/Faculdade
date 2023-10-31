import mysql.connector

def main():
    # Coloca os dados
    mydb = mysql.connector.connect(
        host="localhost",
        user="celiols",
        password="1234",
        database="sakila"
    )

    # Cria o famoso cursor
    cursor = mydb.cursor()

    # Realiza o query do mysql
    query = "SELECT COUNT(DISTINCT a.first_name) as 'nomes diferentes' from actor a"
    cursor.execute(query)
    
    print("Número de nomes diferentes em atores:", cursor.fetchone()[0])

    # Fecha o cursor e o mysql
    cursor.close()
    mydb.close()

if __name__ == "__main__":
    main()
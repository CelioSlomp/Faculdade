import mariadb

def main():
    # *Passar o user, password e database de acordo com o seu computador
    conn = mariadb.connect(database="bancoDados",   # O banco de dados
                            host="localhost",       # Endereco do banco de dados
                            user="root",            # O usuario com premissoes (de preferencia root)
                            password="1234",        # A senha de usuario
                            port=3300)
    # *Passar o user, password e database de acordo com o seu computador
    
    cursor = conn.cursor()
    atributosBd = ""            # Todos os atributos
    atributosBdSemId = ""       # Os atributos sem o Id
    atributosBdTipoIn = ""      # Os atributos sem o Id com o seu tipo para "in" de parametro
    atributosBdPar = ""         # Os atributos de parâmetro
    identificador = ""          # O identificador
    atributosSets = ""          # Os '=' para o update
    atributosBdTipoOut = ""     # Os atributos sem o Id com o seu tipo para "out" de parametro

    try:
        nomeTabela = input("Digite o nome da tabela: ")

        cursor.execute("show columns from ".__add__(nomeTabela).__add__(";"))


        listaColunas = cursor.fetchall() # pega os resultados do show columns
        # print(listaColunas) # para printar os atributos da tabela      

        for i in listaColunas:              # pega o identificador e coloca todo o resto 
            if i[3] == 'PRI':               # está meio feio, mas eu gostaria que fizesse
                identificador = i           # tudo em um laço só para não ficar muito lento
            else:
                # Adiciona aquilo necessário para a variável virar parâmetro
                parametro = i[0] + "Par, "
                atributosBdSemId += i[0] + ", "
                atributosBdPar += parametro
                atributosBdTipoIn += i[0] + "Par " + i[1] + ", "
                atributosBdTipoOut += "out " + i[0] + "Par " + i[1] + ", "
                atributosSets += i[0] + "=" + parametro
                atributosBd += i[0] + ", "

        # Remove os ', ' do final da string
        atributosSets = atributosSets[:-2]
        atributosBdTipoIn = atributosBdTipoIn[:-2]
        atributosBdPar = atributosBdPar[:-2]
        atributosBd = atributosBd[:-2]
        atributosBdSemId = atributosBdSemId[:-2]
        atributosBdTipoOut = atributosBdTipoOut[:-2]

        # executa os 'create procedure ...' no banco de dados
        cursor.execute(criarInsert(nomeTabela, atributosBdSemId, identificador, atributosBdPar, atributosBdTipoIn))
        cursor.execute(criarDelete(nomeTabela, identificador))
        cursor.execute(criarUpdate(nomeTabela, atributosBdTipoIn, identificador, atributosSets))
        cursor.execute(criarSelect(nomeTabela, atributosBdTipoOut, identificador, atributosBd, atributosBdPar))

    except mariadb.Error as erroMariaDB:
        print(erroMariaDB) # Printa o erro do mysql, geralmente é da tabela que não existe ou o bd que nao existe

def criarInsert(nomeTabela, atributosBdSemId, identificador, atributosBdPar, atributosBdTipoIn):
    codigoQuery = "create procedure if not exists " + nomeTabela + "_insere(\
    out " + identificador[0] + "Par " + identificador[1] + ", " + atributosBdTipoIn + ")\
    begin\
    insert into " + nomeTabela + " (" + atributosBdSemId + ") values (" + atributosBdPar + ");\
    SELECT LAST_INSERT_ID() into " + identificador[0] + "Par;\
    end;"

    return codigoQuery

def criarSelect(nomeTabela, atributosBdTipoOut, identificador, atributosBd, atributosBdPar):
    codigoQuery = "create procedure if not exists " + nomeTabela + "_seleciona(\
    in " + identificador[0] + "Par " + identificador[1] + ", " + atributosBdTipoOut + ")\
    begin\
    select " + atributosBd + " into " + atributosBdPar + "\
    from " + nomeTabela + " where " + identificador[0] + "=" + identificador[0] + "Par;\
    end;"

    return codigoQuery

def criarUpdate(nomeTabela, atributosBdTipoIn, identificador, atributosSets):
    codigoQuery = "create procedure if not exists " + nomeTabela + "_atualiza(\
    in " + identificador[0] + "Par " + identificador[1] + ", " + atributosBdTipoIn + ")\
    begin\
    update " + nomeTabela + " set " + atributosSets + " \
    where " + identificador[0] + " = " + identificador[0] + "Par;\
    end;"

    return codigoQuery

def criarDelete(nomeTabela, identificador):
    codigoQuery = "create procedure if not exists " + nomeTabela + "_deleta(in " + identificador[0] + "Par int)\
    begin\
    delete from " + nomeTabela + " where " + identificador[0] + " = " + identificador[0] + "Par;\
    end;"

    return codigoQuery


if __name__ == "__main__":
    main()
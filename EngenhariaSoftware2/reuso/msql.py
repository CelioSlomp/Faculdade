import mysql.connector
from xml.dom import minidom

def principal(cursor):
    # *Passar o user, password e database de acordo com o seu computador

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
        identificadores = []

        for i in listaColunas:              # pega o identificador e coloca todo o resto 
            if i[3] == 'PRI':               # está meio feio, mas eu gostaria que fizesse
                identificador = i           # tudo em um laço só para não ficar muito lento
                identificadores.append(i)
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

        cursor.execute(criarInsert(nomeTabela, atributosBdSemId, identificador, atributosBdPar, atributosBdTipoIn, identificadores))
        cursor.execute(criarDelete(nomeTabela, identificador, identificadores))
        cursor.execute(criarUpdate(nomeTabela, atributosBdTipoIn, identificador, atributosSets, identificadores))
        cursor.execute(criarSelect(nomeTabela, atributosBdTipoOut, identificador, atributosBd, atributosBdPar, identificadores))

    except mysql.connector.Error as erroMysql:
        print(erroMysql) # Printa o erro do mysql, geralmente é da tabela que não existe ou o bd que nao existe

def criarInsert(nomeTabela, atributosBdSemId, identificador, atributosBdPar, atributosBdTipoIn, identificadores):

    if len(identificadores) == 1:
        codigoQuery = "create procedure if not exists " + nomeTabela + "_insere(\
        out " + identificador[0] + "Par " + identificador[1] + ", " 
        codigoQuery += atributosBdTipoIn + ") begin\
        insert into " + nomeTabela + " (" + atributosBdSemId + ") values (" + atributosBdPar + ");"
        
        codigoQuery += "SELECT LAST_INSERT_ID() into " + identificador[0] + "Par; end"

    else:
        chavesPrim = ""
        chavesPrimSemPar = ""
        for i in identificadores:
            chavesPrimSemPar += i[0] + "Par, "
            chavesPrim += "in " + i[0] +"Par " + i[1] + ", "
        
        if len(chavesPrimSemPar) > 1:
            chavesPrimSemPar = chavesPrimSemPar[:-2]
        
        codigoQuery = "create procedure if not exists " + nomeTabela + "_insere(" + \
        chavesPrim + atributosBdTipoIn + ") begin insert into " + nomeTabela + " values (" + chavesPrimSemPar + ", " + atributosBdPar + "); end"

    return codigoQuery

def criarSelect(nomeTabela, atributosBdTipoOut, identificador, atributosBd, atributosBdPar, identificadores):

    wheres = ""
    chavesPrim = ""
    for i in identificadores:
        chavesPrim += "in " + i[0] +"Par " + i[1] + ", "
        wheres += i[0] + "=" + i[0] + "Par and "

    wheres = wheres[:-4]

    codigoQuery = "create procedure if not exists " + nomeTabela + "_seleciona(" + chavesPrim + \
    atributosBdTipoOut + ")\
    begin\
    select " + atributosBd + " into " + atributosBdPar + "\
    from " + nomeTabela + " where " + wheres + "; end"

    return codigoQuery

def criarUpdate(nomeTabela, atributosBdTipoIn, identificador, atributosSets, identificadores):
    wheres = ""
    chavesPrim = ""
    for i in identificadores:
        chavesPrim += "in " + i[0] +"Par " + i[1] + ", "
        wheres += i[0] + "=" + i[0] + "Par and "
    
    wheres = wheres[:-4]
    

    codigoQuery = "create procedure if not exists " + nomeTabela + "_atualiza(" + \
    chavesPrim + atributosBdTipoIn + ")\
    begin\
    update " + nomeTabela + " set " + atributosSets + " \
    where " + wheres+ "; \
    end"

    return codigoQuery

def criarDelete(nomeTabela, identificador, identificadores):
    wheres = ""
    if len(identificadores) == 1:
        codigoQuery = "create procedure if not exists " + nomeTabela + "_insere(\
        out " + identificador[0] + "Par " + identificador[1] + ", " 
        wheres += identificador[0] + "=" + identificador[0] + "Par"
    else:
        chavesPrim = ""
        for i in identificadores:
            chavesPrim += "in " + i[0] +"Par " + i[1] + ", "
            wheres += i[0] + "=" + i[0] + "Par and "
        
        wheres = wheres[:-4]

    codigoQuery = "create procedure if not exists " + nomeTabela + "_deleta(" + chavesPrim[:-2] + ")\
    begin\
    delete from " + nomeTabela + " where " + wheres + "; end"

    return codigoQuery

if __name__ == "__main__":
    principal()
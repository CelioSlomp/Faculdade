import xml.etree.ElementTree as ET

def criarTabela():
    arq = ET.parse(input("Digite o nome do arquivo que possui a tabela: "))
    tab = arq.getroot()

    atributosTabela = []
    nomeTabela = tab.get('nome')

    for i in tab[0]:
        # 'i' vai ser uma das 'colunas', portanto, 'i.keys()' resultara em todas
        # as tags que a coluna vai ter.
        dictGeral = {} # Cria um dicionario para colocar os tipos dos atributos
        for j in i.keys():
            if j == 'null' and i.get(j) == 'nao':
                dictGeral[j] = 'not null'
            else:
                dictGeral[j] = i.get(j)

        atributosTabela.append(dictGeral)

    try:
        chavePrim = tab[1] # Pega a tag chaveprimaria
        chavePrim = chavePrim[0] # Pega as colunas
        chavePrim = chavePrim[0].text # pega o nome que vai ser a chave primaria
        # print(chavePrim) # printa o nome da chave primaria 

        for i in atributosTabela:
            if i['nome'] == chavePrim:
                i['ai'] = 'auto_increment'
                i['chavePrim'] = 'primary key'

    except:
        print("Não possui chave primária")


    atributosTabela = criarAtributosFormat(atributosTabela)

    codigoQuery = 'create table ' + nomeTabela + ' (' + atributosTabela + ');'

    return codigoQuery

def criarAtributosFormat(atributosTabela):
    atTabCopia = atributosTabela
    stringAtributos = ''
    for atributos in atTabCopia:
        for i in atributos:
            
            if atributos[i] == 'string':
                stringAtributos += "varchar(" + atributos['tamanho'] + ")"
            elif i == 'tamanho':
                pass
            else:
                stringAtributos += atributos[i] + " "
                
        stringAtributos += ", "

    return stringAtributos[:-2]

if __name__ == "__main__":
    criarTabela()
import xml.etree.ElementTree as ET

def criarTabela():
    arq = ET.parse(input("Digite o nome do arquivo que possui a tabela: "))
    #arq = ET.parse("tabela.xml")
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
        chavesPrimarias = []
        chavePrim = tab[1] # Pega a tag chaveprimaria
        chavePrim = chavePrim[0] # Pega as colunas
        for chave in chavePrim:
            chavesPrimarias.append(chave.text) # Adiciona os nomes das chaves primarias
        
        # print(chavesPrimarias) # printa o nome da chave primaria 
        tamChaves = len(chavesPrimarias)

        for i in atributosTabela:
            if i['nome'] in chavesPrimarias:
                if tamChaves == 1:
                    i['ai'] = 'auto_increment'
                i['chavePrim'] = 'primary key'

    except:
        print("Não possui chave primária")


    atributosTabela = criarAtributosFormat(atributosTabela, chavesPrimarias)

    codigoQuery = 'create table ' + nomeTabela + ' (' + atributosTabela + ');'

    print(codigoQuery) # Printa o codigo que vai ser executado

    return codigoQuery

def criarAtributosFormat(atributosTabela, chavesPrimarias):
    atTabCopia = atributosTabela
    stringAtributos = ''
    for atributos in atTabCopia:
        for i in atributos:
            if atributos[i] == 'string':
                stringAtributos += "varchar(" + atributos['tamanho'] + ")"
            elif i == 'tamanho' or i == 'chavePrim':
                pass
            else:
                stringAtributos += atributos[i] + " "
                
        stringAtributos += ", "
    if len(chavesPrimarias) >= 1:
        strChaves = ''
        for i in chavesPrimarias:
            strChaves += i + ', '
        
        stringAtributos += 'primary key ( ' + strChaves[:-2] + ')'
        return stringAtributos
    return stringAtributos[:-2]

if __name__ == "__main__":
    criarTabela()
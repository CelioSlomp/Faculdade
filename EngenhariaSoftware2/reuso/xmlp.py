import xml.etree.ElementTree as ET

def main():
    arq = ET.parse('tabela.xml')
    tab = arq.getroot()

    atributosTabela = []

    for i in tab[0]:
        # 'i' vai ser uma das 'colunas', portanto, 'i.keys()' resultara em todas
        # as tags que a coluna vai ter.
        dictGeral = {} # Cria um dicionario para colocar os tipos dos atributos
        for j in i.keys():
            dictGeral[j] = i.get(j)

        atributosTabela.append(dictGeral)

    print(atributosTabela)

if __name__ == "__main__":
    main()
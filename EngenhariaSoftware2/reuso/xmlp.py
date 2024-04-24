import xml.etree.ElementTree as ET

def main():
    arq = ET.parse('tabela.xml')
    tab = arq.getroot()

    '''
        Perguntar se precisa criar a tabela e então fazer as procedures, ou é só as procedures
        sabendo que a tabela já foi criada.
    '''

if __name__ == "__main__":
    main()
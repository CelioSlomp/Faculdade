from pyftpdlib.authorizers import DummyAuthorizer
from pyftpdlib.handlers import FTPHandler
from pyftpdlib.servers import FTPServer

def main():
    # Cria o authorizer para liberar acesso ao usuario
    authorizer = DummyAuthorizer()

    # Adiciona o usuario 'user' com as permissoes de leitura e escrita
    # A pasta utilizada é do meu computador pessoal, precisa ser trocada em outras maquinas
    authorizer.add_user("user", "12345", "C:/Users/slomp/OneDrive/Área de Trabalho/Faculdade/RedesComputadores2/FTP", perm="elradfmw")

    # Cria o tratador de eventos FTP
    handler = FTPHandler
    handler.authorizer = authorizer 

    # Define a porta e o ip
    # Portas abaixo de 1023 causar algum problema
    servidor_ftp = FTPServer(("0.0.0.0", 2121), handler)

    # Iniciando o servidor FTP
    print("Servidor FTP iniciado")
    servidor_ftp.serve_forever()

if __name__ == "__main__":
    main()
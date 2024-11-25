from ftplib import FTP

def conectar_ftp(serverIp, porta, user, senha):
    ftp = FTP()
    try:
        # Conectar ao servidor FTP e realiza o login
        ftp.connect(serverIp, porta)
        ftp.login(user, senha)
        print(f"Conectado ao servidor FTP")
        return ftp
    
    except Exception as e:
        print("Erro:", e)
        return False

def baixar_arquivo(ftp, arquivo):
    # Cria o arquivo na pasta local
    with open(arquivo, 'wb') as f:
        # 'RETR nome' é um comando FTP para receber algum arquivo do servidor
        ftp.retrbinary(f"RETR {arquivo}", f.write)
    print("Arquivo baixado com sucesso.")

def main():
    # Dados do servidor FTP
    serverIp = "127.0.0.1"
    porta = 2121

    # Dados do usuario
    usuario = "user"
    senha = "12345"

    # Conectar ao servidor FTP
    ftp = conectar_ftp(serverIp, porta, usuario, senha)
    if ftp:
        # Baixar o arquivo
        arquivo = "arquivo.jpg"  # Nome do arquivo no servidor
        baixar_arquivo(ftp, arquivo)

        # Desconecta do servidor FTP
        ftp.quit()
        print("Desconectado do servidor FTP.")

if __name__ == "__main__":
    main()
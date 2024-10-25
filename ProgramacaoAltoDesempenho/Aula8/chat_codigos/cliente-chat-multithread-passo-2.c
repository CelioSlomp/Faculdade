// Execute com ./executavel [usuario] [host] [porta], onde
// [usuario] deve ser o seu nome de usuário.
// [host] deve ser o servidor.
// [porta] deve ser a porta na qual o servidor está escutando.

#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#define TAMANHO_BUFFER 1024

// Descritor de arquivo (file descriptor) do socket do servidor.
// O descritor de arquivo é um identificador numérico usado para acessar o socket em operações de leitura, escrita e gerenciamento.
static int socketFd;

int main(int argc, char *argv[]) {
    char *nome;
    struct sockaddr_in enderecoServidor;
    struct hostent *host;
    long porta;

    if (argc != 4) {
        fprintf(stderr, "Considere executar o programa da seguinte forma:\n./executavel [usuario] [host] [porta]\n");
        exit(1);
    }

    nome = argv[1];
    // Obtém informações sobre o host (nome do servidor) a partir do DNS.
    host = gethostbyname(argv[2]);
    porta = atoi(argv[3]);

    printf("Ativando o cliente...\n");

    return 0;    
}
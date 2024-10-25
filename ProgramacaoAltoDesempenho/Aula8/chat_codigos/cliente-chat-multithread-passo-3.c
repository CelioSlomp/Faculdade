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

// Configura e conecta ao servidor
void configurarEConectar(struct sockaddr_in *enderecoServidor, struct hostent *host, int socketFd, long porta) {
    memset(enderecoServidor, 0, sizeof(enderecoServidor));
    enderecoServidor->sin_family = AF_INET;
    enderecoServidor->sin_addr = *((struct in_addr *)host->h_addr_list[0]);
    enderecoServidor->sin_port = htons(porta);
    
    // Tenta estabelecer uma conexão com o servidor.
    if (connect(socketFd, (struct sockaddr *) enderecoServidor, sizeof(struct sockaddr)) < 0) {
        perror("Não foi possível conectar ao servidor.");
        exit(1);
    }
}

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

    printf("Ativando o cliente...\n");
    
    // Obtém informações sobre o host (nome do servidor) a partir do DNS.
    if ((host = gethostbyname(argv[2])) == NULL) {
        fprintf(stderr, "Não foi possível obter o nome do host.\n");
        exit(1);
    }

    porta = atoi(argv[3]);
    
    // Cria um socket para a comunicação com o servidor.
    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Não foi possível criar o socket.\n");
        exit(1);
    }

    // Configura e conecta ao servidor.
    configurarEConectar(&enderecoServidor, host, socketFd, porta);

    printf("Cliente conectado!\n");
    
    return 0;
}
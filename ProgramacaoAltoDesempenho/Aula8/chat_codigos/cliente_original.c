// Cliente

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

// Manipulador de interrupção para informar o servidor sobre o fechamento do socket e a saída do programa
void manipuladorInterrupcao(int sigNaoUsado) {
    // Alterado para evitar o warning -Wstringop-overread (tentativa de escrita, neste caso, em posição de memória além do limite da string "\sair\n").
    // if (write(socketFd, "/sair\n", TAMANHO_BUFFER - 1) == -1)
    if (write(socketFd, "/sair\n", 6) == -1)
        perror("Falha ao escrever no socket: ");

    close(socketFd);
    exit(1);
}

// Constrói uma mensagem formatada com o nome do usuário e timestamp
void construirMensagem(char *resultado, char *nome, char *msg) {
    char timestamp[12]; // Tamanho suficiente para [HH:MM:SS] + espaço
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);

    strftime(timestamp, sizeof(timestamp), "[%T] ", info); // Formata o timestamp

    memset(resultado, 0, TAMANHO_BUFFER);
    strcpy(resultado, timestamp);
    strcat(resultado, "@");
    strcat(resultado, nome);
    strcat(resultado, " diz: ");
    strcat(resultado, msg);
}

// Loop principal do chat
void loopChat(char *nome, int socketFd) {
    fd_set descritoresCliente;
    char mensagemChat[TAMANHO_BUFFER];
    char bufferChat[TAMANHO_BUFFER], bufferMensagem[TAMANHO_BUFFER];

    while (1) {
        FD_ZERO(&descritoresCliente);
        FD_SET(socketFd, &descritoresCliente);
        FD_SET(0, &descritoresCliente);
        
        // Monitora eventos de leitura em descritores de arquivo (socket e stdin).
        if (select(FD_SETSIZE, &descritoresCliente, NULL, NULL, NULL) != -1) {
            for (int fd = 0; fd < FD_SETSIZE; fd++) {
                if (FD_ISSET(fd, &descritoresCliente)) {
                    if (fd == socketFd) {
                        int numBytesLidos = read(socketFd, bufferMensagem, TAMANHO_BUFFER - 1);
                        bufferMensagem[numBytesLidos] = '\0';
                        printf("%s", bufferMensagem);
                        memset(&bufferMensagem, 0, sizeof(bufferMensagem));
                    }
                    else if (!fd) {
                        fgets(bufferChat, TAMANHO_BUFFER - 1, stdin);
                        
                        // Verifica se o usuário digitou "/sair" ou "/sair [alguma coisa]" para sair do chat.
                        if (!strncmp(bufferChat, "/sair\n", 6) || !strncmp(bufferChat, "/sair ", 6))
                            manipuladorInterrupcao(-1);
                        else {
                            construirMensagem(mensagemChat, nome, bufferChat);
                            
                            // Envia a mensagem para o servidor através do socket.
                            if (write(socketFd, mensagemChat, TAMANHO_BUFFER - 1) == -1)
                                perror("Falha ao escrever no socket: ");
                            memset(&bufferChat, 0, sizeof(bufferChat));
                        }
                    }
                }
            }
        }
    }
}

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

// Define um descritor de arquivo como não bloqueante
void definirNaoBloqueante(int fd) {
    int flags = fcntl(fd, F_GETFL);
    if (flags < 0)
        perror("fcntl falhou");

    flags |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flags);
}

void verificarNaoBloqueante(int fd) {
    int flags = fcntl(fd, F_GETFL);
    if (flags < 0) {
        perror("fcntl falhou");
    }
    else {
        if (flags & O_NONBLOCK)
            printf("O descritor de arquivo %d é não bloqueante.\n", fd);
        else
            printf("O descritor de arquivo %d não é não bloqueante.\n", fd);
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
    
    // Caso deseje ver se o padrão do fd é não bloqueante, você pode descomentar as linhas abaixo.
    // Assumindo que 0 seja não bloqueante, você pode remover a instrução definirNaoBloqueante(0);
    // verificarNaoBloqueante(socketFd);
    // verificarNaoBloqueante(0);

    // Define o socket e stdin como não bloqueantes.
    definirNaoBloqueante(socketFd);
    definirNaoBloqueante(0);

    // Configura um manipulador de sinal para capturar interrupções e sair controladamente.
    signal(SIGINT, manipuladorInterrupcao);

    // Inicia o loop principal do chat.
    loopChat(nome, socketFd);

    return 0;
}
// Servidor

// Execute com ./executavel [porta], onde
// [porta] deve ser um número acima de 1023, por exemplo, 1234.
// Ela será a porta na qual o servidor escutará e receberá conexões.

#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define TAMANHO_BUFFER 1024

// Struct que representa uma fila de mensagens usando um array de caracteres.
typedef struct {
    char *buffer[TAMANHO_BUFFER]; // Armazena as mensagens na fila.
    int inicio, cauda; // Índices para controlar a fila.
    int cheia, vazia; // Flags que indicam se a fila está cheia ou vazia.
    pthread_mutex_t *mutex; // Mutex para sincronização.
    pthread_cond_t *naoCheia, *naoVazia; // Variáveis de condição para sincronização.
} Fila;

// Struct contendo dados importantes para o funcionamento do servidor.
typedef struct {
    fd_set descritoresLeituraServidor; // Conjunto de descritores de leitura para o servidor.
    int socketFd; // Descritor do socket do servidor.
    int socketsClientes[TAMANHO_BUFFER]; // Array de descritores de sockets dos clientes.
    int numClientes; // Número atual de clientes conectados.
    pthread_mutex_t *mutexListaClientes; // Mutex para lista de clientes.
    Fila *filaMensagens; // Fila de mensagens do servidor.
} DadosServidor;

// Struct simples para armazenar DadosServidor e o novo socket do cliente.
typedef struct {
    DadosServidor *dados;
    int socketCliente;
} DadosHandlerCliente;

int main(int argc, char *argv[]) {
    // Declaração de uma estrutura para armazenar informações do servidor.
    struct sockaddr_in serverAddr;

    int porta;

    // Verifica se foi fornecida uma porta na linha de comando.
    if (argc == 2)
        porta = atoi(argv[1]);
    else {
        fprintf(stderr, "Considere executar o programa da seguinte forma:\n./executavel [porta]\n");
        exit(1);
    }

    printf("Ativando o servidor...\n");

    return 0;
}
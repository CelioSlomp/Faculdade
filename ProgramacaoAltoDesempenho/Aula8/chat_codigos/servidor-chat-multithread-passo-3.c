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

// Inicializa a fila de mensagens do servidor.
Fila* inicializarFila() {
    // Aloca memória para a estrutura de fila.
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila == NULL) {
        perror("Não foi possível alocar mais memória!");
        exit(EXIT_FAILURE);
    }

    // Inicializa os valores da fila.
    fila->vazia = 1;
    fila->cheia = fila->inicio = fila->cauda = 0;

    // Aloca e inicializa um mutex para proteger operações na fila.
    fila->mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
    if (fila->mutex == NULL) {
        perror("Não foi possível alocar mais memória!");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_init(fila->mutex, NULL);

    // Aloca e inicializa variáveis condicionais para sinalização de fila não cheia e não vazia.
    fila->naoCheia = (pthread_cond_t *) malloc(sizeof(pthread_cond_t));
    if (fila->naoCheia == NULL) {
        perror("Não foi possível alocar mais memória!");
        exit(EXIT_FAILURE);   
    }
    pthread_cond_init(fila->naoCheia, NULL);

    fila->naoVazia = (pthread_cond_t *) malloc(sizeof(pthread_cond_t));
    if (fila->naoVazia == NULL) {
        perror("Não foi possível alocar mais memória!");
        exit(EXIT_FAILURE);
    }
    pthread_cond_init(fila->naoVazia, NULL);

    return fila;
}

// Insere uma mensagem no final da fila de mensagens do servidor.
void enfileirar(Fila *fila, char* mensagem) {
    // Armazena a mensagem no buffer da fila na posição da cauda.
    fila->buffer[fila->cauda] = mensagem;

    // Move a posição da cauda para o próximo índice no buffer circular.
    fila->cauda++;

    // Verifica se a cauda atingiu o final do buffer circular e, se sim, volta para o início.
    if (fila->cauda == TAMANHO_BUFFER)
        fila->cauda = 0;

    // Se a cauda alcançou a cabeça da fila, significa que a fila está cheia.
    if (fila->cauda == fila->inicio)
        fila->cheia = 1;

    // Marca a fila como não vazia.
    fila->vazia = 0;
}

// Remove e retorna a mensagem mais antiga da fila de mensagens do servidor.
char* desenfileirar(Fila *fila) {
    // Obtém a mensagem mais antiga da fila (na posição da cabeça).
    char* mensagem = fila->buffer[fila->inicio];

    // Move a cabeça da fila para a próxima posição.
    fila->inicio++;

    // Verifica se a cabeça atingiu o final da fila e a reinicia se necessário.
    if (fila->inicio == TAMANHO_BUFFER)
        fila->inicio = 0;

    // Verifica se a fila está vazia após a remoção.
    if (fila->inicio == fila->cauda)
        fila->vazia = 1;

    // Marca a fila como não cheia, pois um elemento foi removido.
    fila->cheia = 0;

    // Retorna a mensagem removida.
    return mensagem;
}

// Libera a memória associada à fila.
void destruirFila(Fila *fila) {
    // Destroi o mutex associado à fila.
    pthread_mutex_destroy(fila->mutex);

    // Destroi as variáveis de condição associadas à fila (para controle de cheio e vazio).
    pthread_cond_destroy(fila->naoCheia);
    pthread_cond_destroy(fila->naoVazia);

    // Libera a memória alocada para o mutex.
    free(fila->mutex);

    // Libera a memória alocada para as variáveis de condição.
    free(fila->naoCheia);
    free(fila->naoVazia);

    // Libera a memória alocada para a própria estrutura de fila.
    free(fila);
}

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
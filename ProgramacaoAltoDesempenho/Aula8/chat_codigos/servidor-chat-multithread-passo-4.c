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

// Remove o socket da lista de sockets de cliente ativos e fecha-o.
void removerCliente(DadosServidor *dados, int socketCliente) {
    // Obtém o mutex para acessar com segurança a lista de clientes ativos.
    pthread_mutex_lock(dados->mutexListaClientes);
    
    // Procura o socket do cliente na lista de clientes ativos.
    for (int i = 0; i < TAMANHO_BUFFER; i++) {
        if (dados->socketsClientes[i] == socketCliente) {
            dados->socketsClientes[i] = 0;
            close(socketCliente);
            dados->numClientes--;

            // Sai do loop depois de encontrar o socket.
            i = TAMANHO_BUFFER;
        }
    }
    
    // Libera o mutex para permitir outros acessos concorrentes à lista de clientes ativos.
    pthread_mutex_unlock(dados->mutexListaClientes);
}

// Handler do cliente que lida com mensagens recebidas do cliente.
void *handlerCliente(void *dhc) {
    // Converte o ponteiro genérico de dados de handler do cliente de volta para o tipo DadosHandlerCliente.
    DadosHandlerCliente *dadosHandler = (DadosHandlerCliente *)dhc;
    DadosServidor *dadosServidor = (DadosServidor *)dadosHandler->dados;

    // Obtém a fila de mensagens e o socket do cliente deste handler.
    Fila *fila = dadosServidor->filaMensagens;
    int socketCliente = dadosHandler->socketCliente;

    char bufferMensagem[TAMANHO_BUFFER];
    while (1) {
        // Lê mensagens recebidas do cliente e armazena no buffer.
        int numBytesLidos = read(socketCliente, bufferMensagem, TAMANHO_BUFFER - 1);
        bufferMensagem[numBytesLidos] = '\0';

        // Se o cliente enviou "/sair\n", remove-o da lista de clientes e fecha o socket dele.
        if (!strncmp(bufferMensagem, "/sair\n", 6) || !strncmp(bufferMensagem, "/sair ", 6)) {
            fprintf(stderr, "Cliente desconectado. Socket: %d.\n", socketCliente);
            removerCliente(dadosServidor, socketCliente);
            return NULL; // Encerra a thread do cliente.
        }
        else {
            // Espera até que a fila não esteja cheia antes de inserir uma mensagem.
            while (fila->cheia) {
                pthread_cond_wait(fila->naoCheia, fila->mutex);
            }

            // Obtém lock na fila, insere a mensagem na fila, libera o lock e sinaliza a variável condicional.
            pthread_mutex_lock(fila->mutex);
            fprintf(stderr, "Inserindo mensagem na fila: %s", bufferMensagem);
            enfileirar(fila, bufferMensagem);
            pthread_mutex_unlock(fila->mutex);
            pthread_cond_signal(fila->naoVazia); // Notifica o handler de mensagens que há uma nova mensagem na fila.
        }
    }
}

// Thread para lidar com novas conexões. Adiciona o fd do cliente à lista de fds do cliente e gera uma nova thread handlerCliente para ele.
void *novoHandlerCliente(void *dados) {
    // Converte o ponteiro genérico de dados de volta para o tipo DadosServidor.
    DadosServidor *dadosServidor = (DadosServidor *)dados;

    while(1) {
        // Aceita uma nova conexão de cliente e obtém o socket do cliente.
        int socketCliente = accept(dadosServidor->socketFd, NULL, NULL);

        // Verifica se a conexão foi aceita com sucesso.
        if(socketCliente > 0) {
            fprintf(stderr, "Servidor aceitou novo cliente. Socket: %d.\n", socketCliente);

            // Obtém lock na lista de clientes.
            pthread_mutex_lock(dadosServidor->mutexListaClientes);

            // Verifica se o número de clientes ativos ainda não atingiu o limite.
            if (dadosServidor->numClientes < TAMANHO_BUFFER) {
                // Adiciona o novo cliente à lista de sockets de clientes ativos.
                for (int i = 0; i < TAMANHO_BUFFER; i++) {
                    // Encontra uma posição vazia na lista de sockets de clientes.
                    if (!FD_ISSET(dadosServidor->socketsClientes[i], &(dadosServidor->descritoresLeituraServidor))) {
                        dadosServidor->socketsClientes[i] = socketCliente;
                        i = TAMANHO_BUFFER; // Sai do loop.
                    }
                }

                // Adiciona o novo socket à lista de descritores de leitura do servidor.
                FD_SET(socketCliente, &(dadosServidor->descritoresLeituraServidor));

                // Gera uma nova thread para lidar com mensagens do cliente.
                DadosHandlerCliente dhc;
                dhc.socketCliente = socketCliente;
                dhc.dados = dadosServidor;

                pthread_t threadCliente;
                if (!pthread_create(&threadCliente, NULL, (void *)&handlerCliente, (void *)&dhc)) {
                    // Incrementa o contador de clientes ativos e exibe uma mensagem.
                    dadosServidor->numClientes++;
                    fprintf(stderr, "Cliente entrou no chat. Socket: %d.\n", socketCliente);
                }
                else
                    close(socketCliente); // Fecha o socket em caso de falha na criação da thread.
            }

            // Libera o lock na lista de clientes.
            pthread_mutex_unlock(dadosServidor->mutexListaClientes);
        }
    }
}

// Handler de mensagens que espera até que a fila de mensagens não esteja vazia e envia em broadcast para os clientes.
void *handlerMensagens(void *dados) {
    // Converte os dados genéricos para o tipo de estrutura DadosServidor.
    DadosServidor *dadosServidor = (DadosServidor *)dados;

    // Obtém a referência para a fila de mensagens do servidor.
    Fila *fila = dadosServidor->filaMensagens;

    // Obtém a referência para o array de sockets dos clientes.
    int *socketsClientes = dadosServidor->socketsClientes;

    while(1) {
        // Obtém um bloqueio no mutex da fila.
        pthread_mutex_lock(fila->mutex);

        // Aguarda até que a fila de mensagens não esteja vazia.
        while(fila->vazia) {
            pthread_cond_wait(fila->naoVazia, fila->mutex);
        }

        // Remove a mensagem mais antiga da fila.
        char* mensagem = desenfileirar(fila);

        // Libera o bloqueio do mutex da fila e sinaliza que não está mais cheia.
        pthread_mutex_unlock(fila->mutex);
        pthread_cond_signal(fila->naoCheia);

        // Mensagem em broadcast para todos os clientes conectados.
        fprintf(stderr, "Mensagem em broadcast: %s", mensagem);

        // Envia a mensagem para todos os clientes ativos.
        for(int i = 0; i < dadosServidor->numClientes; i++) {
            int socket = socketsClientes[i];
            if (socket != 0 && write(socket, mensagem, TAMANHO_BUFFER - 1) == -1)
                perror("Falha na escrita do socket: ");
        }
    }
}

// Configura e associa o socket a um endereço IP e porta específicos.
void associarSocket(struct sockaddr_in *serverAddr, int socketFd, long port) {
    // Limpa a estrutura serverAddr para garantir que não haja dados residuais.
    memset(serverAddr, 0, sizeof(*serverAddr));
    
    // Define o tipo de endereço como IPv4.
    serverAddr->sin_family = AF_INET;
    
    // Configura o endereço IP para INADDR_ANY, que significa "escutar em todas as interfaces de rede".
    serverAddr->sin_addr.s_addr = htonl(INADDR_ANY);
    
    // Configura a porta do servidor para a porta especificada.
    serverAddr->sin_port = htons(port);

    // Tenta associar o socket ao endereço e porta especificados.
    if (bind(socketFd, (struct sockaddr *)serverAddr, sizeof(struct sockaddr_in)) == -1) {
        perror("Falha ao associar o socket: ");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    // Declaração de uma estrutura para armazenar informações do servidor.
    struct sockaddr_in serverAddr;
    
    int porta;

    // Declaração do descritor de arquivo do socket.
    int socketFd;

    // Verifica se foi fornecida uma porta na linha de comando.
    if (argc == 2)
        porta = atoi(argv[1]);
    else {
        fprintf(stderr, "Considere executar o programa da seguinte forma:\n./executavel [porta]\n");
        exit(1);
    }

    printf("Ativando o servidor...\n");

    // Cria um novo socket usando o protocolo IPv4 e TCP.
    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Falha na criação do socket.");
        exit(1);
    }

    // Associa o socket ao endereço e porta especificados.
    associarSocket(&serverAddr, socketFd, porta);

    // Inicia o servidor para ouvir novas conexões na porta especificada.
    if (listen(socketFd, 1) == -1) {
        perror("Falha na escuta: ");
        exit(1);
    }

    return 0;
}
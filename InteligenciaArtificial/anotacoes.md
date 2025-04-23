#Anotações do livro de Russel de Inteligência Artificial

## Capitulo 2

#### Precisa colocar os anteriores também.

### 2.3

#### Não deterministico x deterministico

Determinístico: O próximo estado de "environment" depende das ações realizadas pelo agente;
Não determinístico: O próximo estado não depende das ações do agente.

Por exemplo, um motorista de carro, o próximo estado não depende do agente (motorista), pois o motor do carro pode simplesmente explodir, ter trânsito, etc. Enquanto que o mundo do robô aspirador de pó depende do agente (robô), já que caso o ambiente esteja sujo, é culpa do agente e caso contrário também. 

#### Episódico x sequencial

Episódico: Cada agente pensa naquele momento, sem pensar no futuro. Em outras palavras, o próximo episódio não depende do episódio anterior. Um exemplo é um agente que detecta falhas em um processo de montagem, a próxima peça não depende do erro da peça anterior;

Sequencial: O próximo estado depende do estado anterior, fazendo com que o agente tenha que pensar no futuro. Um exemplo é um bot que joga xadrez, o próximo movimento depende exclusivamente do movimento realizado anteriormente.

#### Estático x dinâmico

Dinâmico: Um processo é dinâmico quando o estado pode mudar enquanto o agente está processando. Um exemplo disso é um motorista de carro, enquanto ele está dirigindo, pode acontecer imprevistos;

Estático: Um processo não muda durante a execução. Um exemplo é um jogo de palavras cruzadas, o jogo não muda enquanto ô agente escreve uma palavra.

### 2.4 A estrutura dos agentes

agente = arquitetura + programa

## Capitulo 3

* Actions(state s) -> retorna um set infinito de ações que podem ser executados em s;
* Result(s,a) -> retorna o estado que resulta fazendo a ação a no estado s;
* Action-Cost(s,a,s') -> retorna o custo de aplicar a ação a no estado s para chegar no estado s';

### 3.3 Algoritmos de busca

Um algoritmo de busca recebe um problema e retorna a solução (ou uma falha).

#### 3.3.1 Best-first algorithm

Figura 3.7 apresenta o algoritmo "guloso", cuja finalidade é retornar o primeiro caminho de grafos que o algoritmo encontrar ou uma falha. Dessa forma, não retorna necessariamente o melhor caminho.

#### 3.3.3 Caminho redundante

É um caminho que leva ao mesmo lugar, mas tem um custo maior (por exemplo, o melhor caminho é de 100km, mas um outro caminho é de 250km).

#### 3.3.4 Medindo a performance

* Completude: Se o algoritmo garante encontrar uma solução caso haja uma;
* Ótimo custo: Se o algoritmo consegue achar a melhor solução;
* Complexidade de tempo; Se o algoritmo consegue achar uma solução em tempo polinomial;
* Complexidade de espaço: Se o algoritmo consegue achar uma solução com uma quaantidade viável de memória.

### 3.4 Estratégias de busca desinformada

O agente não tem ideia do quão perto ele está do estado de destino. 

#### 3.4.1 Busca em largura

O agente começa pela raíz, e abre primeiro os nós filhos da raíz, então abre todos os netos da raíz, e por aí vai. Na figura 3.9 está o pseudo-código.

Este não é um algoritmo ótimo, pois ele acha a melhor solução cujas ações temnham o mesmo custo, mas não quando há custos diferentes.

#### 3.4.5 Busca bidirecional

O algoritmo inicia uma busca pelo ponto de partida e uma da chegada. Dessa forma, o algoritmo tem O(b^{d/2} + b^{d/2}), muito menor que O(b^{d}).

### 3.5 Estratégias de buscas informadas (heurísticas)

O agente recebe dicas de onde encontrar a solução no formato h(n)

h(n) é o custo estimado do menor caminho do nó n para o destino.

#### 3.5.2 Busca A*

Não entendi muito bem, tenho que ler novamente caso precise explicar.

A* é um algoritmo "best-first" avaliada como f(n) = g(n) + h(n)

onde g(n) é o custo do caminho do estado inicial para o nó n

então, f(n) é o custo estimado do melhor caminho que continua de n para o destino.

na Figura 3.18 é mostrado o progresso da busca. O destino é Bucharest, mas o algoritmo selecona primeiro Pitesti, pois possui o custo 417, enquanto que Bucharest possui 450. Visando o menor caminho. No passo (f), um caminho para Bucharest é encontrado com o custo de 418 (o menor), portanto, este caminho é escolhido como o melhor.

A busca A* é completa, mas pode não ser ótima, pois o custo depende da heurística utilizada.



#### 3.5.3 Busca em contorno

Cria um contorno no espaço do estado. Na Figura 3.20 pode ter uma ideia de como funciona. Após isso, ele vai expandindo com a busca A* nos nós de menor custo até o destino.

#### 3.5.6 Busca heurística bidirecional

Nós podemos utilizar o f(n) = g(n) + h(n), mas não tem nenhuma garantia que chegaria na melhor solução, nem que seria eficiente, mesmo com uma boa heurística.

Esta busca tem uma notação diferente para os nós que vão para "forward", que tem como raíz o estado inicial e "backward", que tem como o destino como raíz.

Se tivermos uma boa heurística, a busca A* é a melhor opção, enquanto que se tivermos uma heurística mediana, a busca bidirecional é preferida por expandir menos nós. Mas se tivermos uma heurística ruim, a busca não é mais focado no destino e a busca bidirecional tem a mesma complexidade que A*.

### 3.6 Funções heurísticas

Nesta parte veremos como a heurística afeta a performance de busca.

#### 3.6.1 O efeito da precisão da heurística na performance

Uma forma de caracterizar a qualidade da heurística é o "effective branching factor b*". Se os nós de A* é N e o depth é d, então

N+1 = 1 + b* + (b*)^2 + ... + b(*)^d

Uma boa heurística teria o valor de b* perto de 1.

#### 3.6.2 Gerando heurísticas de problemas relaxados

Problemas com menos restrições nas ações são chamados de problemas relaxados. O grafo "state-space" de um problema relaxado é um supergrafo do "original state space" por causa que a remoção de restrições criam bordas ao grafo.

Como este problema cria bordas ao grafo, qualquer solução no problema original é também uma solução ao problema relaxado. "The cost of an optimal solution to a relaxed problem is an admissible heuristic for the original problem".

#### 3.6.4 Gerando heuristicas com "landmarks"

A précomputação pode consumir tempo, mas apenas precisa ser feita uma vez. Esta técnica é utilizada com mapas (como o Google Maps).

São criados "atalhos" que ficam salvos.

#### Aprendendo a buscar melhor

Um agente pode aprender a realizar a busca de uma melhor forma e o método está no conteito de "Metalevel state space", onde cada estado captura o estado computacional interno do programa que está uscando num estado ordinário.

## Capitulo 4 Busca em ambientes complexos

### 4.1 Busca local e problemas de otimização

Este capítulo quer saber apenas de achar uma configuração final, não o caminho para tal.

Busca local não quer saber do caminho, ele procura nos nós vizinhos. Isso é vantajoso por usar pouca memória.

#### 4.1.1 Busca de "Hill-climbing"

Esta busca é tambpem chamada de busca local gulosa, pois ela pega um bom estado vizinho sem pensar pra frente, de onde ir depois.

* Maxima local: É um pico maior do que os estados vizinho, mas é menor que o maximo global. Na Figura 4.3 é possível ver um pico local, onde qualquer vizinho vai deixar o resultado ainda pior.

Obs.: Tem mais coisas aqui, vale dar uma outra olhada

### 4.4 Busca em ambientes parcialmente observáveis

O foco é o agente terá ações cujo objetivo é reduzir a incerteza do estado atual.

#### 4.4.1

Ele deu exemplo do mundo do aspirador de pó, que basta utilizar apenas uma lateral para chegar em um lugar sem ter nenhum sensor.

### 4.5 Agentes de busca online de ambientes desconhecíveis


Agentes que utilizam a busca offline computam uma solução completa antes de realizar alguma ação, enquanto que os agentes de uma busca online intercalam computação e ação, tomando uma ação e então observam o ambiente.

A busca online é melhor para ambientes dinâmicos e semi-dinâmicos pelo fato de ser custoso ficar pensando a resposta ótima.

Isso pode ter um custo alto, pois não calculando a solução ótima, o agente pode se encontrar em um "barco sem remo".

#### 4.5.1 Problemas de busca online

Um problema se busca online é solucionada intercalando computação, "sensing" e ação. O agente apenas sabe
* actions(s): as ações legais do estado s;
* c(s,a,s'): o custo de aplicar a ação a no estado s para chegar no estado s';
* is-goal(s): o destino.

Obs.: este agente não tem acesso à função Result(s,a), pois pense num labirinto: o agente não sabe para onde está indo.

Busca online é vulnerável a "dead ends", que são estados que não possuem saída. Na figura 4.20 tem mostra que para o agente que está no estado A, ir pra baixo ou pra cima é possuem o mesmo resultado.

No livro serão apresentados apenas algoritmos que não possuem "dead ends".

#### 4.5.3 Busca local online

Busca "hill-climbing" já é um algoritmo de busca online por deixar os nós salvos na memória.

O algoritmo "learning real-time A*" (LRTA*) constrói um mapa de ambiente na tabela de resultados, que atualiza o custo estimado do estado que ele acabou de sair e escolhe o melhor movimento de acordo com seu custo estimado.

Diferente de A*, este algoritmo não é completo para espaços com infinitos estados e tem ordem O(n^2) (para n estados).

## Capitulo 5 Busca adversária e jogos

Neste capítulo será abordado ambientes competitivos, ou seja, ambientes onde dois ou mais agentes competem visando o mesmo destino.

### 5.1 Teoria de jogo

#### 5.1.1 Jogos de soma zero com dois jogadores

Foi apresentado o jogo da velha, e algumas características, como informação perfeita (todos os jogadores conseguem ver o jogo inteiro) e alguns métodos que serão utilizados.

Além disso, na Figura 5.1 foi aberto uma árvore do jogo da velha com todos os jogos possíveis (um pouco menos que 9!).

### 5.2 Decisão ótima em jogos

Para jogos com vários finais possíveis, o algoritmo busca minimax é necessário.

Dado uma árvore, a estratégia ótima pode ser determinado pelo valor de minimax de acordo com cara estado da árvore.

#### 5.2.1 O algoritmo de busca minimax

Na figura 5.3 está o algoritmo de busca minimax.

Numa profundidade m com b movimentos legais, a complexidade é de O(b^m). Para o xadrez, este algoritmo não é utilizado, pois possui uma ramificação de 35 com uma profundidade de 80, cria aproximadamente 10^(123) estados.

#### 5.2.2 Alpha-beta pruning

Os algoritmos são exponenciais à profundidade da árvore, mas podemos cortar pela metado algumas vezes.

Na Figura 5.7 está o algoritmo alpha-beta. E na Figura 5.5 está o progresso do algoritmo numa árvore.

### 5.3 Busca em árvore alfa-beta com heurística

Pode-se finalizar a busca antes e aplicar a função de avaliação heurística aos estados, ou seja, tratando nós não-terminais como nós terminais.

#### 5.3.1 Funções de avaliação

Uma função de avaliação heurística Evel(s,p) retorna a utility esperada estimada do estado s para o jogador p.

A função de avaliação não sabe qual estado é qual, mas retorna um único valor que estima as proporções de estados com cada resultado.


EVAL(s) = w1f1(s) + w2f2(s) + ⋯ + wnfn(s) = ∑wifi(s)

Em um exemplo de xadrez, cada fi é uma característica de posição e o w é o peso (o quão importante essa característica é).

#### 5.3.2 Cortando a busca

* Parei de ler o capítulo 5 para ler direto o capitulo 6 por conta de tempo (Quinta feira 17/04/2025 com o seminário na semana seguinte).

## Capítulo 6 Constraint Satisfaction Problems (CSP)

Os algoritmos de busca CSP tomam vantagens da estrutura de estados e usa a heurística geral ao invés da heurística específica de domínio para habilitar a solução de problemas complexos.

A ideia é eliminar buscas encontrando variáveis que combinadas violam as restrições.

### 6.1 Defining Constraint Satisfaction Problems

Um constraint satisfaction problem consiste em 3 componentes X, D, e C.

* X é o conjunto de variáveis {X1, ..., Xn};
* D é o conjunto de domínios {D1, ..., Dn}, para cada variável;
* C é o conjunto de restrições que especificam as combinações permitidas de valores.

Um domínio Di consiste em valores {v1, ..., vk} para a variável Xi. Por exemplo, uma variável booleana teria o domínio {true, false}. Cada restrição Cj consiste no par (escopo, relação), onde o escopo é uma tupla de variáveis que participam da restrição e relação é a relação que define os valores que cada variável pode assumir.

O CSP lida dando valores às variáveis, como {Xi = vi, Xj = vj,...}. Quando não viola nenhuma restrição, é chamado de consistente ou legal. Quando todas as variáveis recebem um valor, é chamado de completo. Enquanto que um parcial deixa algumas variáveis sem nada. Isso é NP-completo (pode ser resolvido em tempo polinomial).

#### 6.1.1 Exemplo de problema: coloração de mapa

A coloração de mapa consiste em pintar ar regiões de um mapa de modo que dois vizinhos não possuam a mesma cor. Para exemplo foi usada a Figura 6.1.

O domínio de cada variável é o domínio Di = {vermelho, verde, azul}. Neste mapa, o sul faz fronteira com todas as outras regiões, portnato, a cor dela deve ser diferente de todos os outros, de modo que:

C = {SA ≠ WA, SA ≠ NT, SA ≠ Q, SA ≠ NSW, SA ≠ V, WA ≠ NT, NT ≠ Q, Q ≠ NSW, NSW ≠ V}.

Existem várias soluções possíveis, uma delas é:

{WA = vermelho,NT = verde,Q = vermelho,NSW = verde,V = vermelho,SA = azul,T = vermelho}.

Existem três vantagens de utilizar o CSP:
* Ele produz uma representação natural de diversos problemas;
* O CSP é rápido e eficiente;
* Ele resolve de forma rápida grandes faixas do espaço de busca que um "atomic state-space" não consegue.

" A search procedure that does not use constraints would have to consider 3^5 = 243 assignments for the five neighboring variables; with constraints we have only 2^5 = 32 assignments to consider, a reduction of 87%."

Com o CSP, uma vez que vimos um parcial violando alguma regra, podemos descartá-lo. Além disso, podemos ver qual tarefa que não é uma solução com as variáveis que descumpriram as regras.

#### 6.1.3 Variações do formalismo CSP

O tipo mais simples de CSP envolve variáveis que possuem domínios discretos e finitos.

CSP com domínios contínuos são estudados na área de pesquisa operacional. Por exemplo, ao marcar um horário para um telescópio observar algo necessita de uma precisão enorme (o início e fim).

Uma categoria de domício contínuo de CSP são os problemas da programação linear, cujas regras são igualdades ou desigualdades lineares. Estes problemas podem ser resolvidos em tempo polinomial.

Além disso, existem tipos de regras, como a restrição unária, que restringe o valor de uma única variável. Por exemplo, no problema da coloração de mapa, podemos falar que a variável SA não pode ser verde. Dada a regra: ((SA), SA != verde).

Restrição binária: trata duas variáveis, como (SA != NSW). Um CSP binário é quando as restrições apenas são unárias e binárias.

Uma restrição que envolve N variáveis é chamada de restrição global. Um exemplo é a restrição "Alldiff", onde todas as variáveis devem ser diferentes. todos os valores de uma linha no jogo Sudoku devem ser diferentes.

Existem duas razoões pelas quais é preferível usar as restrições globais como alldiff:
* É mais fácil e contém menos erros descrever o problema usando o alldiff;
* É possível fazer "special-purpose inference algorithms", que são mais eficientes do que restrições primitivas.

Restrições de preferência indicam qual solução é preferível. Por exemplo, ao criar os horários de aula: podem haver professores que preferem dar aula de noite, equanto que outros preferem dar aula de tarde.

### 6.2 Propagação de restrição: inferência no CSP

Enquanto que um algoritmo de busca normal faz progresso expandindo os nós sucessores. Um algoritmo CSP pode gerar sucessores escolhendo as restrições de novas variáveis, ou fazer um tipo específico de inferência chamado de "propagação de restrição", usando as restrições para reduzir o número de valores legais para uma ou mais variáveis.

Consistência local: se tratarmos cada variável como um nó no grafo e cada restrição binária como uma borda, então o processo de cumprimento da consistência local causa valores inconsistentes.

#### 6.2.1 Consistência do nó

Uma variável é "node-consistent" se todos os valores no domínio de variáveis satisfazem as restrições de uma restrição unária. Um grafo é consistente se todas as variáveis forem consistentes.

#### 6.2.2 Consistência de arco

Uma variável é arco-consistente se todos os valores no domínio satisfazerem as restrições binárias. Por exemplo, a restrição Y = X^2, podemos escrever essa restrição como ((X,Y), ((0,0), (1,1), (2,4), (3,9))).

Para fazer X arco-consistente, reduzimos o dominio de X para {0,1,2,3}. Se fizermos o mesmo para o Y, reduzimos para {0,1,2,4,9}.

No caso do mapa da Austrália: {(red,green),(red,blue),(green,red),(green,blue),(blue,red),(blue,green)} Não importa qual valor escolher pra uma variável, vai ter um valor válido para outra variável.

Algoritmo AC-3 como mais popular para consistência de arco (Figura 6.3).

#### 6.2.3 Consistência de caminho

Suponha que vamos colorir o mapa da Austrália com apenas duas cores: vermelho e azul. A consistência de arco não faz nada por causa que todas as restrições podem ser satisfeitas individualmente com o vermelho de um lado e o azul do outro, mas claramente não há solução, já que é necessário ao menos três cores

A consistência de arco diminui os domínios (restrições unárias) usando os arcos (restrições binárias). A consistência de caminho é usado para problemas como a coloração de mapa, pois ela aperta as restrições binárias usando restrições implícitas inferidas pela observação de três variáveis.

Para fazer o mapa da Austrália ser consistente, vamos fazer o conjunto {WA,SA} consistente em relação ao NT. Primeiramente enumeramos as tarefas consistentes: {WA = vermelho, SA = azul} e {WA = azul, SA = vermelho}. dessa forma, vemos que NT vai comflitar ambos com SA e WA, ou seja, não há solução.

#### 6.2.4 Consistência K

Formas mais fortes de propagação podem ser definidas com a notação de k-consistency. Um CSP é k consistente se em um conjunto de k-1 variáveis e para qualquer tarefa dadas a essas variáveis, o valor consistente pode ser atribuída para uma kº variável.

É um 1-consistente se dado um conjunto vazio, nós podemos fazer qualquer conjunto de uma variável consistente.

Um CSP é fortemente kconsistente se é k-consistente, (k-1)consistente, (k-2)consistente,... e 1consistente.

#### 6.2.5 Restrições Globais

Deu um exemplo do uso do algoritmo AC-3, que cria domínios para cada item e vai removendo os valores desse domínio.

#### 6.2.6 Sudoku

Uma linha, coluna ou bloco é chamado de unidade.

Na Figura 6.4 está um exemplo de um jogo de Sudoku usando o AC-3.

### 6.3 Busca de Backtrackig para CSP

O algoritmo de Backtracking escolhe um valor não atribuído e então tenta todos os valor de domínio dessa variável, tentando achar um valor para solucionar o problema. Ou seja, é um brute-force reduzido ao domínio de cada valor.

Na Figura 6.5 está o algoritmo de backtracking

#### 6.3.1 Variável e ordenando valor

O algoritmo possui a linha

var = Select-Unassigned-Variable(csp, assignment)

Isso é ordenação estática, ou sejam escolhe as variáveis em ordem, e então escolhe aleatoriamente.

A ideia intuitiva: Escolher a variável com menores valores possíveis, ou seja, tem menos valores em seu domínio. Este metodo é chamado de "minimum-remaining-values (MRV)".

#### 6.3.2 Intercalando busca e inferência

Todas vez que uma busca é inciada, nós podemos inferir uma nova redução no domínio das variáveis vizinhas.

Na Figura 6.7 mostra a backtracking search no mapa da Austrália. Quando um domínio ficar vazio, significa que foi encontrado uma inconsistência e o algoritmo volta imediatamente.

#### 6.3.3 Backtracking inteligente

O backjumping faz com que o backtracking evite voltar para problemas que não irão resolver o problema efetivo.

#### 6.3.4 Aprendizado de restrições

Quando se chega em uma contradição, o backjumping fala o quanto se deve voltar, para evitar o brute force.

Então, salvamos os problemas para que caso ocorra novamente, possa ser evitado.

### 6.4 Busca local para CSP

Alguns CSP são mais eficientes utilizando a busca local, que utiliza a heurística de conflitos mínimos.

### 6.5 A estrutura de problemas

Para lidar melhor com problemas do mundo real, basca decompor o problema em subproblemas. Como por exemplo no mapa da Austrália: Tasmânia não está conectada ao território, ou seja, para o problema de coloração, a Tasmânia não faz nenhuma diferença.

Na Figura 6.11 mostra o algoritmo para árvores.

#### 6.5.1 Cutset conditioning

O algoritmo geral funciona como:

* Escolha um subconjunto S das variáveis de CSP de tal forma que o grafo de restrições se transforme em uma árvore após a remoção de S;
* Para cada atribuição possível para as variáveis em S que satisfazem as restrições em S:
* > Remova do domínio das variáveis restantes qualquer valor que seja inconsistente com S;
* > Se o CSP tiver uma solução, retorne junto com as atribuições de S.

#### 6.5.2 Decomposição de árvore



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


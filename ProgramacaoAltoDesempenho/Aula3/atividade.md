# Atividades - 20/09/2024

1) (POSCOMP 2011, Questão 41) O gerenciamento de processos em sistemas
modernos é feito, quase sempre, com o uso de preempção de processos através de
técnicas de compartilhamento de tempo. O que a introdução de processadores com
vários núcleos altera nesse gerenciamento?

a) Torna-se possível a paralelização efetiva de processos concorrentes.

b) Torna-se possível eliminar a condição de corrida em processos concorrentes
executados em paralelo.

c) Torna-se possível o uso de threads para a execução de processos concorrentes.

d) Torna-se possível separar os demais mecanismos de gerenciamento do sistema
operacional do gerenciamento de processos.

e) Torna-se possível o uso de sistemas operacionais multitarefas.

Resposta: Alternativa A.


2) (adaptado de POSCOMP 2008, Questão 53) O algoritmo FIFO (First In, First Out) de
escalonamento de processos é inerentemente preemptivo. Verdadeiro ou falso?

Resposta: Falso. Ele não é preemptivo: Pense em uma fila de banco, se ninguém pode passar na frente do outro, ele não é preemptivo.

3) (AOCP 2012 — BRDE — Analista de Sistemas — DBA) Em sistemas operacionais,
encontramos uma série de algoritmos de escalonamento para facilitar o
gerenciamento de processador. Analise as assertivas e assinale a alternativa que
aponta a(s) correta(s) sobre o escalonamento Shortest-Job- First e o escalonamento
Preemptivo.
I. O escalonamento Shortest-Job-First associa cada processo (ou job) ao seu tempo
de execução. Dessa forma, quando o processador está livre, o processo em estado
de pronto que precisar de menos tempo de UCP para terminar seu processamento é
selecionado para execução.
II. O escalonamento Shortest-Job-First favorece os processos que executam
programas menores, além de reduzir o tempo médio de espera em relação ao FIFO.
III. O escalonamento preemptivo permite que o sistema dê atenção imediata a
processos mais prioritários, como no caso de sistemas de tempo real, além de
proporcionar melhores tempos de respostas em sistemas de tempo compartilhado.
IV. Um algoritmo de escalonamento é dito preemptivo quando o sistema pode
interromper um processo em execução para que outro processo utilize o
processador.

a) Apenas I.

b) Apenas I, II e III.

c) Apenas I, III e IV.

d) Apenas II, III e IV.

e) I, II, III e IV.

Resposta: Alternativa e.

4) (UFSC 2022 — Técnico de TI) Analise as afirmativas abaixo sobre escalonamento
de processos em sistemas operacionais e assinale a alternativa correta.

I. No algoritmo de escalonamento por prioridades, um processo que sofre uma
preempção passa imediatamente para o estado “bloqueado”.

II. O algoritmo First Come First Served (FCFS) é muito indicado para sistemas operacionais interativos.

III. O algoritmo Round-Robin reparte uniformemente o tempo da CPU entre
todos os processos prontos para a execução.

IV. O Algoritmo de Envelhecimento (Aging) pode ser utilizado para evitar o
problema da postergação indefinida existente no algoritmo de escalonamento
por prioridades.

a) Somente as afirmativas III e IV estão corretas.

b) Somente as afirmativas I e III estão corretas.

c) Somente as afirmativas II e IV estão corretas.

d) Somente as afirmativas I, II e III estão corretas.

e) Somente as afirmativas I, II e IV estão corretas.

Resposta: Alternativa a.

5) Considere a existência de três processos cujos dados estão abaixo:

Processo de ID = 1010, Chegada = 0, Execução=4

Processo de ID = 2020, Chegada = 1, Execução=3

Processo de ID = 3123, Chegada = 2, Execução=2

Significado:
ID = PID
Chegada = momento (em unidade de tempo) em que o processo está
pronto.
Execução = tempo necessário para executar o processo.
Calcule o tempo médio de espera dos processos utilizando os algoritmos SJF e FCFS.

Resposta:

SJF: PID 1010 -> PID 3123 -> PID 2020

Explicação PID 3123: Processador vazio entra o PID 1010, com chegada no momento 0, após isso, no momento 1 chega o PID 2020 e logo em seguida o PID 3123, no momento 2. No momento 4, quando o PID 1010 finaliza, o PID 3123 e PID 2020 estão esperando pelo processador e, como o PID 3123 é menor que o PID 2020, ele é escolhido e depois o PID 2020. 

Média de espera: 0 + 2 + 5 = 7 => 7/3 Unidades de tempo.

FCFS: PID 1010 -> PID 2020 -> PID 3123

Explicação: Processador vazio entra o PID 1010, com chegada no momento 0, após isso, no momento 1 chega o PID 2020 e logo em seguida o PID 3123, no momento 2.

Média de espera: 0 + 3 + 5 = 8/3 Unidades de tempo.

6) Implemente um simulador de escalonador de processos preemptivo utilizando
preferencialmente a linguagem C. O simulador deve permitir a criação de processos
com suas respectivas informações, como ID, tempo de chegada, tempo de execução
e prioridade.
O escalonador deve utilizar o algoritmo de escalonamento de prioridades.
Para executar seu código, crie processos informando o ID, tempo de chegada,
tempo de execução e prioridade de cada processo. O exercício pede apenas uma
simulação, então criar processos é uma tarefa hipotética que consiste apenas em
declarar e utilizar a estrutura criada (ou seja, não é necessário usar fork()).
O simulador deve continuar a execução dos processos até que todos tenham sido
concluídos.
Responda no fim código quantas unidades de tempo foram necessárias até a
conclusão do último processo e quantas unidades de tempo o processador ficou
ocioso.
Dica: Utilize a função usleep(), declarada em unistd.h, para simular o tempo
de execução de cada processo.
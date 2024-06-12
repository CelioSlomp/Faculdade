# Aula 10 - Análise Semântica - 12/06/2024

---

## Atividade de aula

### Exercício 1

(3+4)*(5+6)

Resposta no papel

---

## Atividade final do PDF

### Exercício 1

Usar variáveis não declaradas é um erro sintático ou semântico?

Resposta: É um erro semântico, pois no analisador sintático é visto como "identificador fazendo algo", mas esse identificador não foi definido.

### Exercício 2

(POSCOMP 2018) Sobre tipos de dados, é correto afirmar que: <br>
a) Tipos booleanos são valores que são mantidos fixos pelo compilador.<br>
b) O double é um tipo inteiro duplo com menor precisão do que o tipo inteiro.<br>
c) A faixa de valores dos tipos inteiros tem somente dois elementos: um para verdadeiro e outro para falso.<br>
d) Uma conversão de tipos implícita consiste em uma modificação do tipo de dados executado, automaticamente, pelo compilador.<br>
e) Vetores, matrizes e ponteiros são exemplos de tipos de dados primitivos (básicos).<br>

Resposta: D

---

## Atividade SIGAA

Analise o trecho de código-fonte abaixo (em linguagem C), identifique e classifique os erros em: léxicos, sintáticos e semânticos. <br>
int I4, I3, I@; -> Erro léxico por conta do 'I@' <br>
I4 = 0;<br>
while (I4>=0); { -> Erro sintático, ';' está não está certo<br>
    I3 = I3 + 1; -> Erro semântico, I3 não possui valor<br>
}<br>
I4 = 'a'; -> Erro semântico, I4 é do tipo 'int'<br> 
I3 = I4$5; -> Erro léxico, $ não está no alfabeto da linguagem <br>


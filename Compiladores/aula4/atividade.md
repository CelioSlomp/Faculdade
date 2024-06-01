# Aula 4 - Análise Léxica (Continuação) - 22/05/2024
---
## Atividade de Revisão PDF
---
### Exercício 1
Como seriam as regras de produção de uma Gramática Livre de Contexto – GLC que gera números inteiros?
```
S -> AB <br>
A -> Cnum | vazio
B -> numB | vazio
num -> 0 .. 9 | vazio
C -> + | - | vazio
```

---
### Exercício 2
Como seriam as regras de produção de uma Gramática Regular – GR que gera números inteiros?

```
S -> [((+|-|vazio) (0 .. 9)) | vazio ][0 .. 9]*
```

---
### Exercício 3
Na expressão x = (y + tmp) * 30;

#### a. Quais são os lexemas e suas respectivas categorias?
```
x,y,tmp -> identificador
=,+,* -> operador
(,) -> separador
; -> delimitador
30 -> constante
```

#### b. Quais são os tokens?

```
<id, 1>
<=, >
<(, >
<id, 2>
<+, >
<id, 3>
<), >
<*, >
<const, >
<;, >
```
---

### Exercício 4
(POSCOMP QUESTÃO 68) A tarefa principal de um analisador léxico consiste em ler os caracteres da entrada do programa-fonte, agrupá-los em lexemas e gerar uma sequência de tokens que será enviada ao analisador sintático. Sobre o analisador léxico, analise as assertivas abaixo: <br>
- I. Além da identificação de lexemas, outras tarefas podem ser realizadas por esse analisador, tais como: remoção de comentários e espaços em branco e a associação de mensagens de erros às linhas do programa-fonte.<br>
- II. Token é a unidade básica do texto-fonte. Pode ser representado por três informações: a classe do token, que representa o tipo do token reconhecido, o valor do token, que é o texto do lexema reconhecido e a posição que indica o local do texto-fonte (linha e coluna) onde ocorreu o token.<br>
- III. Expressões regulares e geradores de analisadores léxicos são notações utilizadas para especificar os padrões de lexemas.<br>
- IV. Na análise léxica, uma representação intermediária do tipo árvore é criada. Esta apresenta a estrutura gramatical da sequência de tokens.<br>

Quais estão corretas?<br>
Apenas I. <br>
Apenas II.<br>
Apenas IV.<br>
- Apenas I e II. <br>
  
Apenas III e IV.<br>

## Atividade Final do PDF
---
### Exercício 1
Existe(m) erro(s) léxico(s) no código abaixo? Se sim, qual?

```c
#include <stdio.h>
    // Função principal
    int main(int argc, char const *argv[]) {
        short dvar = 4444;
        short a = 1;
        short $teste$ = 5555;
        short #teste# = 666;

        printf("%hd\n", dvar + a);
        printf("%hd\n", $teste$);
        printf("%hd\n", #teste#);

        return 0;
        /* Fim do código
    }
```
Resposta:
```
#teste# -> duas vezes,  
/* não é finalizado
```

---
### Exercício 2
Qual é o erro léxico do código abaixo e como ele pode ser corrigido?

```c
#include <stdio.h>

    int main() {
        short $teste$ = 666666 + 1;
        printf("%hd\n", $teste$);
        return 0;
    }
```
Resposta:
```
O problema está no '666666', pois o tipo short nao suporta.
```

---
### Exercício 3
Utilizando flex, elabore um analisador léxico para cada caso:
* que reconheça expressões no formato binário (iniciando com 0b) e no formato hexadecimal (iniciando com 0x).
* que reconheça strings que representem placas de veículos brasileiros. Para isso, considere os padrões antigo e novo. Faça com que o analisador reconheça as entradas com espaço na posição em que ele pode ser esperado. Por exemplo, as placas ABC1234 e ABC 1234 devem ser reconhecidas.
* que reconheça as palavras reservadas da linguagem Python.
* que reconheça as matrículas de 2020 dos alunos do IFC.

Os exemplos criados ainda são bastante simples. Além disso, os itens léxicos costumam ser divididos em categorias, o que é especialmente válido para linguagens de programação. Tomando como base a classificação de itens léxicos apresentada em aulas anteriores, utilize o (f)lex para criar um scanner que reconheça itens léxicos válidos. A classificação apresentada continha palavras reservadas, identificadores, constantes, operadores, textos e delimitadores (ou separadores). Salve-as em um arquivo lexico-seu-nome.l.

Alguns dos testes que serão feitos:
> +.1 + (+.1) <br>
> int x = 0; while (x++ > 10) { printf("Vou passar em Compiladores!\n"); }<br>
> unsigned int minhaNota = 5; if (nota < 6) { printf("REPROVADO"); }<br>
> int main() { printf("Hello, world!\n"); return 0; }<br>
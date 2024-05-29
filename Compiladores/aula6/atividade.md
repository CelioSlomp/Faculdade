# Aula 6 - Análise sintática - 29/05/2024
---

### Anotações

-> Olhar cabeçote de leitura

---
### Exercicio Shift Reduce


Empilhar -> E <br>
Reduzir -> R <br>
Aceitar <br>
Erro

S -> [L] | a <br>
L -> L, S | S
|Pilha|Entrada|Ação|
|-|-|-|
|$|[a,a]$|E|
|$[|a,a]$|E|
|$[a|,a]$|R|
|$[S|,a]$|R|
|$[L|,a]$|E|
|$[L,|a]$|E|
|$[L,a|]$|R|
|$[L,S|]$|R|
|$[L|]$|E|
|$[L]|$|R|
|$S|$|A|
---

### Exercício 1

Dada a gramática abaixo, identifique os conjuntos FIRST e FOLLOW, crie a tabela M e reconheça -(-id(id))$. O símbolo inicial da gramática é A. <br>
A → -A | (A) | CB<br>
B → -A | ε<br>
C → idD<br>
D → (A) | ε<br>

-> Faltou colocar o follow
|First|Simbolo| |Follow|Simbolo|
|-|-|-|-|-|
|A|-, (, id| |A| |
|B|-, $ | |B| |
|C| id | |C| |
|D| (, $ | |D| |

#### Tabela de entradas

| |-|(|id|$|
|-|-|-|-|-|
|A|A -> -A| A -> (A)| A -> CB||
|B|B -> -A||| B -> $|
|C|C -> idD||||
|D||D -> (A)||D -> $|

#### Tabela do exercício

|Pilha|Entrada|Ação|
|-|-|-|
|$A|-(-id(id))$|A -> -A|
|$A - |-(-id(id))$| consome -|
|$A |(-id(id))$|A -> (A)|
|$)A(|(-id(id))$| consome (|
|$)A|-id(id))$|A -> -A|
|$)A-|-id(id))$|consome -|
|$)A|id(id))$|A -> CD|
|$)DC|id(id))$| C -> idD|
|$)DD id|id(id))$| consome id|
|$)DD|(id))$|D -> (A)|
|$)D)A(|(id))$|consome (|
|$)D)A|id))$|A -> CB|
|$)D)BC|id))$|C -> idD|
|$)DBDid|id))$|consome id|
|$)D)BD|))$|D -> $|
|$)D)B|))$|B -> $|
|$)D)|))$|consome )|
|$)D|)$| D -> $|
|$)|)$| consome )|
|$|$|consome $|

---

### Exercício 2
Dada a gramática abaixo, cujo símbolo inicial é C, e a sequência de tokens: x x y y x, faça o que se pede: <br>
C → X Y <br>
X → x | x X <br>
Y → y | y Y <br>

a) Verifique se a sequência de tokens pertence à linguagem definida pela gramática fornecida.<br>

Empilhar -> E <br>
Reduzir -> R <br>
Aceitar <br>
Erro

|Pilha|Entrada|Ação|
|-|-|-|
|$|x x y y x$|E|
|$x| x y y x$|E|
|$x |x y y x$|E|
|$x x| y y x$|R|
|$x X| y y x$|R|
|$X| y y x$|E|
|$X |y y x$|E|
|$X y| y x$|E|
|$X y | x$|E|
|$X y y| x$|R|
|$X y Y| x$|R|
|$X Y| x$|R|
|$C| x$|E|
|$C |x$|E|
|$C x|$|E|
|$C x|$|Erro|

b) Se a sequência não pertencer à gramática, identifique o ponto onde o erro sintático ocorreu e explique o motivo do erro. <br>
Resposta: O problema aconteceu com o último " x" pelo fato de que não tem como voltar ao estado inicial (X Y) havendo um x como ultimo argumento.

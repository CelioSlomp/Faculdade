# Aula 3 - Análise Léxica - 20/05/2024
---
## Atividade de aula
---
### Exercício 1

Como seriam as regras de uma (*) para nomes de variáveis em C?

#### a. GLC (Gramática livre de contexto):
>S -> AB <br>
>A -> letra | _ | $<br>
>B -> letraB | $B | _B | numB | conj. vazio<br>
>letra -> a | b | ... | z  | A | B | ... | z<br>
>num -> 0 | 1 | .. | 9<br>

#### b. GR (Gramática Regular):
>id -> [letra | _ | $][letra | _ | $ | num]* <br>
>letra -> a | b | ... | z  | A | B | ... | z<br>
>num -> 0 | 1 | .. | 9<br>
---
### Exercício 2
int y = 1;
int x = 0;
x = x + y *10;
x = (y+tmp)*30;
        
Quais são os lexemas, suas categorias e os tokes?

Obs.: Precisa repetir todas as ocorrencias dos lexemas, pelo fato de que o
compilador nao vai saber se o x é um identificador ou um parametro ou seja 
lá o que for. Também precisa colocar na ordem que se lê.

formato: lexema - categoria -> token

    int - reservada     <int, >
    y - identificador   <id, 1>
    = - operador        <=, >
    1 - constante       <const, >
    ; - delimitador     <;, >

    int - reservada     <int, >
    x - identificador   <id, 2>
    = - operador        <=, >
    0 - constante       <const, >
    ; - delimitador     <;, >

    x - identificador   <id, 2>
    = - operador        <=, >
    x - identificador   <id, 2>
    + - operador        <+, >
    y - identificador   <id, 1>
    * - operador        <*, >
    10 - constante      <const, >

    x - identificador   <id, 2>
    = - operador        <=, >
    ( - separador       <sep, >
    y - identificador   <id, 1>
    + - operador        <+, >
    tmp - identificador <id, 3>
    ) - separador       <sep, >
    * - operador        <*, >
    30 - constante      <const, >
    ; - delimitador     <;, >

---
## Atividade Sigaa
Para a expressão salario = remuneracaoBase * 2 + comissao, responda:

---
### Exercício 1
Quem são os lexemas?

---
### Exercício 2
Quais são os tokens?

---
### Exercício 3
Como ficaria a tabela de símbolos?

---
### Exercício 4
Alguma das respostas anteriores seria diferente se a expressão fosse 
    salario = remuneracaoBase + remuneracaoBase + comissao? Justifique por que 
    cada resposta anterior permanece igual ou fica diferente.
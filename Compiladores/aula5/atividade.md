# Aula 5 - Tabela de símbolos - 27/05/2024
---
## Atividade PDF
---
### Exercício 1
Há dois tipos de atividades básicas em um compilador: análise e síntese. A tabela de símbolos é criada em qual dessas atividades?

```
As entradas da tabela são criadas durante a análise.
```

---
### Exercício 2
a seguinte afirmação: A tabela de símbolos é uma estrutura utilizada para armazenar principalmente os nomes de funções, variáveis, classes etc. Entre os atributos presentes na tabela, normalmente estão a tipagem, o escopo, os argumentos, os tipos de retornos, etc. Verdadeiro ou falso?
```
Verdadeiro
```
---
### Exercício 3
Os tipos de dados dos identificadores 
são adicionados na tabela de símbolos 
ainda na fase de análise léxica. 
Verdadeiro ou falso?

```
Falso, na análise é colocado apenas as entradas, a tabela é preenchida durante todas as etapas da compilação. Os tipos são colocados na parte da semântica.

" As entradas da tabela são criadas durante a análise, pelo scanner, pelo parser e pelo analisador semântico. "
```

---
### Exercício 4

Para cada aplicação listada abaixo, à esquerda, se for necessário armazenar os dados em uma variável que é a parametrização de uma tabela de símbolos genérica (TS), encontre a parametrização no grupo da direita que fará o trabalho corretamente. Assuma que tipos com colchetes são listas daquele tipo.

1. Para cada ano de calendário desde 1989, o número de estudantes que se graduou no IFC naquele ano.
2. Um dicionário de todos os sinônimos de todas as palavras em português.
3. Contagem de frequência de palavras em um livro.
4. Armazenar uma lista de pessoas vivendo em cada CEP (valor inteiro) e rastrear a idade de cada pessoa lá.
5. Rastrear de que jeito cada senador eleito votou (sim ou não) em alguma moção.
6. Tabela de símbolos de todos os nomes e valores de variáveis locais em uma máquina virtual.

a. TS<Literal, Inteiro> <br>
b. TS<Literal, Lógico><br>
c. TS<Inteiro, Inteiro><br>
d. TS<Literal, Literal[]><br>
e. TS<Literal, ST<Literal, Inteiro>><br>
f. TS<Literal, Objeto><br>

Resposta: 

    1 - c   C
    2 - d   C
    3 - a   X
    4 - e   X
    5 - b   C
    6 - f   X

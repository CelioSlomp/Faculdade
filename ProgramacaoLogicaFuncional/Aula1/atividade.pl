# Atividade 1 do sigaa de Prolog (questões do ENADE)

/*
Questão 1:
(ENADE 2014) Diferentes implementações da linguagem de programação PROLOG permitem predicados 
com parâmetros, aceitam as operações de conjunção e disjunção lógica, utilizando os símbolos 
de vírgula (conjunção) e ponto e vírgula (disjunção), e a negação lógica com o predicado not.

Considere que um programador propôs as cláusulas mostradas a seguir, definidas em uma 
linguagem de programação como PROLOG, como parte da verificação de critérios para seleção 
de candidatos a uma chapa de presidente e vice-presidente de uma empresa. Estas cláusulas 
apresentam as premissas para chegar às conclusões selecionados, desconsiderados e descartado, 
a partir da possibilidade da existência de fatos ou regras com o identificador superior.

superior(jorge).
superior(ana).
selecionados(P,Q) :- superior(P), superior(Q).
desconsiderados(P,Q) :- not(superior(P)); not(superior(Q)).
descartado(P) :- not(superior(P)).

Considerando apenas as colocações e cláusulas acima e a hipótese de mundo fechado 
(closed world assumption), avalie as afirmações a seguir.

I. Para todos os valores dos parâmetros P e Q, o predicado selecionados retornará um valor lógico falso.
    - Falso, retornará verdade para jorge e ana.
II. Para todos valores de P e Q, os predicados selecionados e desconsiderados retornarão valores lógicos diferentes.
    - Verdade.
III. A conjunção dos predicados selecionados e desconsiderados, para quaisquer valores de P e Q, retornará um valor lógico verdadeiro.
    - Falso, pois caso P seja jorge e Q seja paulo, resultará em falso.
IV. Para qualquer valor do parâmetro P, o predicado descartado retornará um valor verdadeiro.
    - Falso, para ana e jorge resultará em falso.
V. A disjunção dos predicados selecionados e desconsiderados, para quaisquer valores de P e Q, retornará um valor lógico verdadeiro.
    - Verdade.

É correto apenas o que se afirma em
A) I e II.
B) I e III.
C) II e V. -> Alternativa correta.
D) III e IV.
E) IV e V.
*/

/*
2. (ENADE 2021) A linguagem PROLOG pertence ao paradigma da programação lógica, no qual a lógica proposicional e algorítmica pode ser expressa na forma de descritores de fatos e regras de produção de respostas. No contexto da árvore genealógica de uma família, analise a seguinte base de fatos descrita em linguagem Prolog.

paide(ana,francisco).
paide(maria,francisco).
paide(luiz,francisco).
maede(jose,maria).
maede(angelica,ana).
paide(luiza,luiz).
paide(joaquim,luiz).
homem(francisco).
homem(jose).
homem(luiz).
homem(joaquim).
mulher(ana).
mulher(maria).
mulher(angelica).
mulher(luiza).

Qual regra lógica de produção está corretamente escrita para verificar uma das situações lógicas em que duas pessoas são irmãs?
a) saoirmas(X,Y) :- paide(X,P), paide(Y,P), X\=Y.                       -> Não verifica se são mulheres.
b) saoirmas(X,Y) :- paide(X,P), paide(Y,P), X\=Y, mulher(X).            -> Não verifica se AMBAS são mulheres.
c) saoirmas(X,Y) :- paide(X,P), paide(Y,P), X\=Y, mulher(X,Y).          -> "mulher(X)" possui apenas um argumento.
d) saoirmas(X,Y) :- paide(X,P), paide(Y,P), X\=Y, mulher(X), mulher(Y). -> Alternativa mais provável (em casos onde a mãe é a mesma? Como fica?).
e) saoirmas(X,Y) :- paide(X,P), maede(Y,M), X\=Y, mulher(X), mulher(Y). -> Retorna verdadeiro para famílias diferentes.
*/


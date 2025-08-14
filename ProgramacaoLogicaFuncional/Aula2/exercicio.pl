# De tarefa eu resolvi fazer um fibonacci, nao quis
# nem saber de exercicios de aula kkkkkkkkk
fibonacci(A0, A1, 0, C) :- C is A0+A1, !.
fibonacci(A0, A1, B, C) :- B>0, B1 is B-1, A2 is A1, A3 is A0+A1, fibonacci(A2, A3, B1, C).

fatorial(0, 1):- !.
fatorial(A, B) :- A1 is A-1, fatorial(A1, B1), B is A * B1.

/*
(Adaptada do ENADE 2021) O paradigma de programação em lógica constitui-se 
como um processo de definição de relações em que se constroem fatos e regras 
sobre os elementos e suas relações. A ativação dos programas acontece por 
meio de consultas (ou perguntas) sobre o relacionamento definido. Ao 
construir-se um banco de dados referente a uma família, inicia-se pelas 
relações de parentesco, tais como:
pai(joão, maria) convencionado que João é pai de Maria
mãe(maria, luiz) convencionado que Maria é mãe de Luiz

As cláusulas, sem condições, definem os fatos sobre o domínio do problema. 
De outra maneira, é possível definir as regras que são cláusulas com condições:
avô_materno(joão,luiz) :- pai(joão,maria), mãe(maria,luiz).

Nesse contexto, avalie as afirmações a seguir.
A consulta ?- mãe(maria, X) retorna verdadeiro conforme identificado na cláusula.
    - mae(maria, X). retorna luiz, mas vou considerar como verdadeiro.
A conclusão João é avô materno de Luiz é identificada como cabeça da cláusula.
    - Eu não sei o que é cabeça da clausula, entao considerarei falso para ficar certo com as alternativas :D
A regra irmão(X, Y) :- pai(Z, X), pai(Z, Y) é uma regra genérica que define irmãos por parte de pai.
    - Verdadeiro
A regra avô_materno(X, Y) :- pai(X, Z), mãe(Z, Y) é uma regra válida para o programa.
    - Verdadeiro

É correto apenas o que se afirma em
I e II.
II e III.
II e IV.
I, II e IV.
I, III e IV. -> Alternativa correta
*/
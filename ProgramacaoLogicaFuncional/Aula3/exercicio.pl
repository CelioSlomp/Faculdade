/*
Imprime os 6 numeros impares seguintes
*/

verificarPar(A, B) :- 
    (
    (A mod 2) =:= 0 
    -> 
    B is (A+1) 
    ; 
    B is A
    ).

seisImpares(A, B) :- 
    B < 6, 
    write(A), 
    nl, 
    A0 is A+2, 
    B0 is B+1, 
    seisImpares(A0,B0).

chamadaFuncaoImpares :- read(A),
    verificarPar(A, B), 
    seisImpares(B, 0), 
    !.

/*
Dado um valor N, fazer a divisão de 2N valores
*/

divisao(_, 0) :- 
    write("solução impossível"), 
    !.
divisao(A, B) :- 
    X is A/B,
    format("~1f", [X]),
    nl.

pedeItens(0) :- !.
pedeItens(X) :- 
    N is X-1, 
    read(A), 
    read(B), 
    divisao(A, B), 
    pedeItens(N).

chamadaProblema :- 
    read(X), 
    nl,
    pedeItens(X).
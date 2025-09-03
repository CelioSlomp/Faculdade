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
*/